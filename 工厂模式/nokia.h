#pragma once
//用一个工厂类封装所有的产品
#include <iostream>
#include <string>

using namespace std;

class Nokia
{
public:
	Nokia();
	virtual ~Nokia();
	virtual bool MakeCall(const string &number) const = 0;
};

