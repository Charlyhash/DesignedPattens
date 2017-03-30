#pragma once

#include "nokia.h"
class N95 : public Nokia
{
public:
	N95();
	virtual ~N95();
	bool virtual MakeCall(const string &number) const;
};