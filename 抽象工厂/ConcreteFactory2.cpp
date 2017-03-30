#include "ConcreteFactory2.h"



ConcreteFactory2::ConcreteFactory2()
{
}


ConcreteFactory2::~ConcreteFactory2()
{
}

AbstractProductA * ConcreteFactory2::CreateProductA()
{
	pA2 = new ProductA2();
	return pA2;
}

AbstractProductB * ConcreteFactory2::CreateProductB()
{
	pB2 = new ProductB2();
	return pB2;
}
