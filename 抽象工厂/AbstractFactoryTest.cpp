#include "AbstractFactory.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractFactory *af1 = new ConcreteFactory1();
	af1->CreateProductA();
	af1->CreateProductB();

	AbstractFactory *af2 = new ConcreteFactory2();
	af2->CreateProductA();
	af2->CreateProductB();

	delete af1; af1 = nullptr;
	delete af2; af2 = nullptr;

	return 0;
}