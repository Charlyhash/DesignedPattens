#include <iostream>
using namespace std;

class War;
class State
{
public:
	virtual void Prophase(){}
	virtual void Metaphase(){}
	virtual void Anaphase(){}
	virtual void End() {}
	
	virtual void CurrentStatus(War *war){}
};

class War
{
private:
	State *m_state; //目前状态
	int m_days;		//战争天数

public:
	War(State* state) : m_state(state), m_days(0){}
	~War() { if (m_state) delete m_state; }
	void SetDays(int day) { m_days = day; }
	int GetDays() { return m_days; }
	void SetStatus(State *s) { delete m_state; m_state = s; }
	void GetStatus() { m_state->CurrentStatus(this); }
};

class EndState :public State 
{
public:
	void End(War* war)
	{
		cout << "战争结束" << endl;
	}

	void CurrentStatus(War *war)
	{
		End(war);
	}
};

class AnaphaseStats : public State
{
public:
	void Anaphase(War* war)
	{
		if (war->GetDays() < 30)
			cout << "第" << war->GetDays() << "天：战争后期，双方拼死一搏" << endl;
		else
		{
			war->SetStatus(new EndState());
			war->GetStatus();
		}
	}

	void CurrentStatus(War *war)
	{
		Anaphase(war);
	}
};

class MetaphaseState :public State
{
public:
	void Metaphase(War *war)
	{
		if (war->GetDays() < 20)
			cout << "第" << war->GetDays() << "天：战争中期，进入相持阶段，双方各有损失" << endl;
		else
		{
			war->SetStatus(new AnaphaseStats());
			war->GetStatus();
		}
	}
	void CurrentStatus(War *war)
	{
		Metaphase(war);
	}
};

class ProphaseState :public State
{
public:
	void Prophase(War *war)
	{
		if (war->GetDays() < 10)
			cout << "第" << war->GetDays() << "天：战争初期，双方你来我往，互相试探对方" << endl;
		else
		{
			war->SetStatus(new MetaphaseState());
			war->GetStatus();
		}
	}
	void CurrentStatus(War *war)
	{
		Prophase(war);
	}
};

//测试
int main()
{
	War *war = new War(new ProphaseState());
	for (int i = 1; i < 40; i += 5)
	{
		war->SetDays(i);
		war->GetStatus();
	}

	delete war; war = nullptr;

	return 0;
}
