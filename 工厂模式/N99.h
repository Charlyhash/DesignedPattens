#pragma once
#include "nokia.h"

class N99 :public Nokia
{
public:
	N99();
	virtual ~N99();
	virtual bool MakeCall(const string &number) const;
};
