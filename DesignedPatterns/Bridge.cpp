#include <iostream>
using namespace std;

//抽象类
class Implementor
{
public:
	virtual void OperationImpl() = 0;
};
//实现类
class ConcreteImplementor :public Implementor
{
public:
	void OperationImpl() override
	{
		cout << "OperatorImpl()..." << endl;
	}
};

//用户调用类
class Abstraction
{
protected:
	Implementor *pImpl_;		//有一个对象指针
public:
	Abstraction(Implementor *pImpl) : pImpl_(pImpl){}

	void Operator()
	{
		pImpl_->OperationImpl();
	}
};

class RedefinedAbstraction :public Abstraction
{
public:
	RedefinedAbstraction(Implementor *pImpl) : Abstraction(pImpl){}

	void Operator()
	{
		pImpl_->OperationImpl();
	}
};

int main()
{
	Implementor *impObj = new ConcreteImplementor();
	Abstraction *absObj = new RedefinedAbstraction(impObj);
	absObj->Operator();
	delete impObj; impObj = nullptr;
	delete absObj; absObj = nullptr;

	return 0;
}