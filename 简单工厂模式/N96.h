#pragma once
#include "nokia.h"

class N96 :public Nokia
{
public:
	N96();
	virtual ~N96();
	virtual bool MakeCall(const string &number) const;
};
