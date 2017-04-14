#include <iostream>
#include <string>
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

	void Show()
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
	void Show()
	{
		cout << "Product B..." << endl;
	}
};

class SimpleFactory
{
public:
	Product* MakeProduct(const string& s)
	{
		if (s == "A")
			return new ProductA();
		else if (s == "B")
			return new ProductB();
		else
		{
			cout << "no product " << s << endl;
			return nullptr;
		}
	}
};

int main()
{
	SimpleFactory *sf = new SimpleFactory();
	Product* p = sf->MakeProduct("B");
	p->Show();
	if (sf)
		delete sf;
	if (p)
		delete p;

	return 0;
}