#pragma once
#include "AbstractFactory.h"
class ConcreteFactory1 :
	public AbstractFactory
{
public:
	ConcreteFactory1();
	~ConcreteFactory1();
	AbstractProductA *CreateProductA();
	AbstractProductB *CreateProductB();
};

