#pragma once
//��һ���������װ���еĲ�Ʒ
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

