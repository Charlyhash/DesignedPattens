#pragma once
#include "nokia.h"
#include "N95.h"
#include "N96.h"
#include "N85.h"

class NokiaSimpleFactory
{
public:
	NokiaSimpleFactory();
	~NokiaSimpleFactory();
public:
	static Nokia* CreateNokia(const string& model);
};
