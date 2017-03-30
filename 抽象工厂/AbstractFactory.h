#pragma once

#include <iostream>
#include "ProductA1.h"
#include "ProductA2.h"
#include "ProductB1.h"
#include "ProductB2.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"

using namespace std;

class AbstractFactory
{
public:
	AbstractFactory();
	virtual ~AbstractFactory();
	virtual AbstractProductA *CreateProductA() = 0;
	virtual AbstractProductB *CreateProductB() = 0;
protected:
	AbstractProductA* pA1;
	AbstractProductA* pA2;
	AbstractProductB* pB1;
	AbstractProductB* pB2;
};

