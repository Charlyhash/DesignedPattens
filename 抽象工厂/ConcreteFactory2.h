#pragma once
#include "AbstractFactory.h"
class ConcreteFactory2 :
	public AbstractFactory
{
public:
	ConcreteFactory2();
	~ConcreteFactory2();
	AbstractProductA *CreateProductA();
	AbstractProductB *CreateProductB();
};

