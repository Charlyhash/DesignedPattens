#include <iostream>
#include <string>
using namespace std;

//�ֻ��� ��������
class Phone
{
public:
	Phone(){}
	virtual ~Phone(){}
	virtual void ShowDecorate(){}
};

//���嶨���ֻ���
class iPhone :public Phone
{
private:
	string name_;
public:
	iPhone(string name):name_(name){}
	~iPhone(){}
	void ShowDecorate() { cout << name_ << "��װ��" << endl; }
};

class NokiaPhone:public Phone
{
private:
	string name_;
public:
	NokiaPhone(string name):name_(name){}
	~NokiaPhone() {}
	void ShowDecorate() { cout << name_ << "��װ��" << endl; }
};

//װ����
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

//����װ������
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
	void AddDecorate()	{ cout << "���ӹҼ�" << endl; }
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
	void AddDecorate() { cout << "��Ļ��Ĥ" << endl; }
};

//�ͻ��˵���
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