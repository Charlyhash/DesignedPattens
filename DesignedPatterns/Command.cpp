#include <iostream>
#include <vector>
using namespace std;

//����ʦ���ࣺ������
class RoastCook
{
public:
	void MakeMutton() { cout << "������" << endl; }
	void MakeChickenWing() { cout << "������" << endl; }
};

//����������
class Command
{
protected:
	RoastCook *receiver;
public:
	Command(RoastCook *r) : receiver(r){ }
	virtual void ExecuteCmd() = 0;
};

//����������
class MakeMuttonCmd :public Command
{
public:
	MakeMuttonCmd(RoastCook* tmp):Command(tmp){}
	void ExecuteCmd() override { receiver->MakeMutton(); }
};

//����������
class MakeChikenWingCmd :public Command
{
public:
	MakeChikenWingCmd(RoastCook* tmp):Command(tmp){}
	void ExecuteCmd() override { receiver->MakeChickenWing(); }
};

//����Ա��:�����߽�ɫ
class Waiter
{
private:
	vector<Command*> commadList;
public:
	void SetCmd(Command* cmd)
	{
		commadList.push_back(cmd);
		cout << "���Ӷ���" << endl;
	}
	//����֪ͨ
	void Notify()
	{
		for (auto iter : commadList)
			iter->ExecuteCmd();

		commadList.clear();
	}

};

int main()
{
	RoastCook* cook = new RoastCook();
	Command* cmd1 = new MakeChikenWingCmd(cook);
	Command* cmd2 = new MakeMuttonCmd(cook);
	Waiter *waiter = new Waiter();

	waiter->SetCmd(cmd1);
	waiter->SetCmd(cmd2);
	
	waiter->Notify();

	return 0;
}