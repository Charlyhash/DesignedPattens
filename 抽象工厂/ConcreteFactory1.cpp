#include "ConcreteFactory1.h"



ConcreteFactory1::ConcreteFactory1()
{
}


ConcreteFactory1::~ConcreteFactory1()
{
}

AbstractProductA * ConcreteFactory1::CreateProductA()
{
	pA1 = new ProductA1();
	return pA1;
}

AbstractProductB * ConcreteFactory1::CreateProductB()
{
	pB1 = new ProductB1();
	return pB1;
}
