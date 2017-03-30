#pragma once
#include "FactoryMethod.h"
#include "N99.h"
#include "nokia.h"

class N99Factory :public FactoryMethod
{
public:
	N99Factory();
	virtual ~N99Factory();
	Nokia* CreateNokia();

};