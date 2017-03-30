#include "N99.h"

N99::N99()
{
	cout << "创建一部N99" << endl;
}

N99::~N99(){}

bool N99::MakeCall(const string &number) const
{
	cout << "我是N99， 我要拨打的电话是：" << number << endl;
	return true;
}
