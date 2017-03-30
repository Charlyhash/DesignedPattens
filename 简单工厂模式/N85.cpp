#include "N85.h"

N85::N85()
{
	cout << "生产一部N85" << endl;
}

N85::~N85()
{
}

bool N85::MakeCall(const string & number) const
{
	cout << "我用的是N85， 我拨打的号码是：" << number << endl;
	return true;
}
