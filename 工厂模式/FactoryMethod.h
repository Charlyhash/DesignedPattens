#pragma once
#include <iostream>
#include <string>
#include "nokia.h"

using namespace std;

class FactoryMethod
{
public:
	FactoryMethod();
	virtual ~FactoryMethod();
	virtual Nokia* CreateNokia() = 0;
};