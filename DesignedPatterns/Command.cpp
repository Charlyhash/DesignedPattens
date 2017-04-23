#include <iostream>
#include <vector>
using namespace std;

//烤肉师傅类：接受者
class RoastCook
{
public:
	void MakeMutton() { cout << "烤羊肉" << endl; }
	void MakeChickenWing() { cout << "烤鸡翅" << endl; }
};

//抽象命令类
class Command
{
protected:
	RoastCook *receiver;
public:
	Command(RoastCook *r) : receiver(r){ }
	virtual void ExecuteCmd() = 0;
};

//烤羊肉命令
class MakeMuttonCmd :public Command
{
public:
	MakeMuttonCmd(RoastCook* tmp):Command(tmp){}
	void ExecuteCmd() override { receiver->MakeMutton(); }
};

//烤鸡翅命令
class MakeChikenWingCmd :public Command
{
public:
	MakeChikenWingCmd(RoastCook* tmp):Command(tmp){}
	void ExecuteCmd() override { receiver->MakeChickenWing(); }
};

//服务员类:请求者角色
class Waiter
{
private:
	vector<Command*> commadList;
public:
	void SetCmd(Command* cmd)
	{
		commadList.push_back(cmd);
		cout << "增加订单" << endl;
	}
	//发送通知
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