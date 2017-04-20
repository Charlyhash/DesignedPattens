#include <iostream>
using namespace std;

//������
class Implementor
{
public:
	virtual void OperationImpl() = 0;
};
//ʵ����
class ConcreteImplementor :public Implementor
{
public:
	void OperationImpl() override
	{
		cout << "OperatorImpl()..." << endl;
	}
};

//�û�������
class Abstraction
{
protected:
	Implementor *pImpl_;		//��һ������ָ��
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