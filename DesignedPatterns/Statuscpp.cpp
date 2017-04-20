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
	State *m_state; //Ŀǰ״̬
	int m_days;		//ս������

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
		cout << "ս������" << endl;
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
			cout << "��" << war->GetDays() << "�죺ս�����ڣ�˫��ƴ��һ��" << endl;
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
			cout << "��" << war->GetDays() << "�죺ս�����ڣ�������ֽ׶Σ�˫��������ʧ" << endl;
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
			cout << "��" << war->GetDays() << "�죺ս�����ڣ�˫������������������̽�Է�" << endl;
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

//����
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
