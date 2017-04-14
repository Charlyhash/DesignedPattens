#include <iostream>
#include <string>

using namespace std;

//父类
class Resume
{
protected:
	string name;
public:
	Resume() {}
	virtual ~Resume(){}
	virtual Resume* Clone() { return NULL; }
	virtual void Set(const string &str){}
	virtual void Show(){}
};

//子类
class ResumeA: public Resume
{
public:
	ResumeA(const string &str)
	{
		name = str;
	}
	~ResumeA(){}
	ResumeA(const ResumeA &r)//使用默认构造函数
	{
		name = r.name;
	}
	ResumeA* Clone() override
	{
		return new ResumeA(*this);
	}
	void Show() override
	{
		cout << "ResumeA name: " << name << endl;
	}
};


class ResumeB : public Resume
{
public:
	ResumeB(const string &str)
	{
		name = str;
	}
	~ResumeB() {}
	ResumeB(const ResumeB &r)//使用默认构造函数
	{
		name = r.name;
	}
	ResumeB* Clone() override
	{
		return new ResumeB(*this);
	}
	void Show() override
	{
		cout << "ResumeB name: " << name << endl;
	}
};

//客户端

int main()
{
	Resume *r1 = new ResumeA("Lucy");
	Resume *r2 = new ResumeB("Bill");
	Resume *r3 = r1->Clone();
	Resume *r4 = r2->Clone();
	r1->Show();
	r2->Show();
	//now delete r1 and r2;
	delete r1;
	delete r2;
	r1 = r2 = nullptr;

	r3->Show();
	r4->Show();

	delete r3; delete r4;
	r3 = r4 = nullptr;

	return 0;

}