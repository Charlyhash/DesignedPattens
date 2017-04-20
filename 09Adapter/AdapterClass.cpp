#include <iostream>
using namespace std;

class Target
{
public:
	virtual void Request()
	{
		cout << "Target::Requst()..." << endl;
	}
};

class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Adaptee::SpecificRequst()..." << endl;
	}
};

class Adapter :public Target, public Adaptee
{
public:
	//调用Adaptee类的SpecificRequst
	void Request()
	{
		Adaptee::SpecificRequest();
	}
};

//client
int main()
{
	Target *t = new Adapter();
	t->Request();

	delete t;
	t = nullptr;

	return 0;
}