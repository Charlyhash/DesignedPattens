#include <iostream>
#include <string>
#include <memory>
using namespace std;

class ProductA
{
public:
	virtual void Show() = 0;
};

class ProductA1 :public ProductA
{
public:
	ProductA1()
	{
		cout << "Create product A1..." << endl;
	}

	void Show() override
	{
		cout << "Product A1..." << endl;
	}
};

class ProductA2 :public ProductA
{
public:
	ProductA2()
	{
		cout << "Create product A2..." << endl;
	}

	void Show() override
	{
		cout << "Product A2..." << endl;
	}
};

class ProductB
{
public:
	virtual void Show() = 0;
};

class ProductB1 :public ProductB
{
public:
	ProductB1()
	{
		cout << "Create product B1..." << endl;
	}

	void Show() override
	{
		cout << "Product B1..." << endl;
	}
};

class ProductB2 :public ProductB
{
public:
	ProductB2()
	{
		cout << "Create product B2..." << endl;
	}

	void Show() override
	{
		cout << "Product B2..." << endl;
	}
};


//抽象工厂类，定义生产A与B类的接口
class Factory
{
public:
	virtual ProductA* MakeProductA() = 0;
	virtual ProductB* MakeProductB() = 0;
};

class Factory1 :public Factory
{
public:
	ProductA* MakeProductA() override
	{
		return new ProductA1();
	}
	ProductB* MakeProductB() override
	{
		return new ProductB1();
	}
};

class Factory2 :public Factory
{
public:
	ProductA* MakeProductA() override
	{
		return new ProductA2();
	}
	ProductB* MakeProductB() override
	{
		return new ProductB2();
	}
};


int main()
{
	shared_ptr<Factory> p1(new Factory1);
	shared_ptr<ProductA> a1(p1->MakeProductA());
	a1->Show();
	shared_ptr<ProductB> b1(p1->MakeProductB());
	b1->Show();
	cout << endl;

	shared_ptr<Factory> p2(new Factory2);
	shared_ptr<ProductA> a2(p2->MakeProductA());
	a2->Show();
	shared_ptr<ProductB> b2(p2->MakeProductB());
	b2->Show();

	return 0;
}