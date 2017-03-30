#pragma once
#include "FactoryMethod.h"
#include "N85.h"
#include "nokia.h"

class N85Factory :public FactoryMethod
{
public:
	N85Factory();
	virtual ~N85Factory();
	Nokia* CreateNokia();

};