#include <iostream>
using namespace std;

class Target
{
public:
	Target() {}
	virtual ~Target(){}
	virtual void Request()
	{
		cout << "Target::Requset()..." << endl;
	}
};

class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Adaptee::SpecificRequest()..." << endl;
	}
};

class Adapter:public Target
{
private:
	Adaptee *adaptee_;
public:
	Adapter():adaptee_(new Adaptee){}

	~Adapter()
	{
		if (adaptee_ != nullptr)
		{
			delete adaptee_;
			adaptee_ = nullptr;
		}
	}

	void Request() override
	{
		adaptee_->SpecificRequest();
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