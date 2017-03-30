#pragma once

#include "nokia.h"
class N85 : public Nokia
{
public:
	N85();
	virtual ~N85();
	bool virtual MakeCall(const string &number) const;
}; 
