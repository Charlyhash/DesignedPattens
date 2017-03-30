#include "N85.h"

N85::N85()
{
	cout << "创建一部N85" << endl;
}

N85::~N85(){}

bool N85::MakeCall(const string &number) const
{
	cout << "我是N85， 我要拨打的电话是：" << number << endl;
	return true;
}
