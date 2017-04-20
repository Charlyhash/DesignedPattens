#include <iostream>
#include <string>
using namespace std;

//手机类 公共抽象
class Phone
{
public:
	Phone(){}
	virtual ~Phone(){}
	virtual void ShowDecorate(){}
};

//具体定义手机类
class iPhone :public Phone
{
private:
	string name_;
public:
	iPhone(string name):name_(name){}
	~iPhone(){}
	void ShowDecorate() { cout << name_ << "的装饰" << endl; }
};

class NokiaPhone:public Phone
{
private:
	string name_;
public:
	NokiaPhone(string name):name_(name){}
	~NokiaPhone() {}
	void ShowDecorate() { cout << name_ << "的装饰" << endl; }
};

//装饰类
class DecoratorPhone :public Phone
{
private:
	Phone* phone_;
public:
	DecoratorPhone(Phone* phone) : phone_(phone){}
	//virtual ~DecoratorPhone()
	//{
	//	if (phone_)
	//		delete phone_;
	//}
	virtual void ShowDecorate() { phone_->ShowDecorate(); }
};

//具体装饰器类
class DecoratorPhoneA :public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone *phone) :DecoratorPhone(phone) {}
	~DecoratorPhoneA(){}
	void ShowDecorate() 
	{
		DecoratorPhone::ShowDecorate(); 
		AddDecorate();
	}

private:
	void AddDecorate()	{ cout << "增加挂件" << endl; }
};

class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone *phone) :DecoratorPhone(phone) {}
	~DecoratorPhoneB() {}
	void ShowDecorate() 
	{ 
		DecoratorPhone::ShowDecorate(); 
		AddDecorate(); 
	}

private:
	void AddDecorate() { cout << "屏幕贴膜" << endl; }
};

//客户端调用
int main()
{
	Phone *p = new NokiaPhone("6300");
	Phone *dpa = new DecoratorPhoneA(p);
	Phone *dpb = new DecoratorPhoneB(p);
	dpb->ShowDecorate();

	delete p; p = nullptr;
	delete dpa; dpa = nullptr;
	delete dpb; dpb = nullptr;

	return 0;
}