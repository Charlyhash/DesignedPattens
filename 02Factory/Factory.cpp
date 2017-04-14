#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Product
{
public:
	virtual void Show() = 0;
};

class ProductA :public Product
{
public:
	ProductA()
	{
		cout << "Create product A..." << endl;
	}

	void Show() override
	{
		cout << "Product A..." << endl;
	}
};

class ProductB :public Product
{
public:
	ProductB()
	{
		cout << "Create product B..." << endl;
	}
	void Show() override
	{
		cout << "Product B..." << endl;
	}
};

class Factory
{
public:
	virtual Product* MakeProduct() = 0;

};

class FactoryA :public Factory
{
	ProductA* MakeProduct() override
	{
		return new ProductA();
	}
};

class FactoryB :public Factory
{
	ProductB* MakeProduct() override
	{
		return new ProductB();
	}
};

int main()
{
	shared_ptr<Factory> f(new FactoryA);
	f->MakeProduct();
	shared_ptr<Factory> f2(new FactoryB);
	f2->MakeProduct();

	return 0;
}