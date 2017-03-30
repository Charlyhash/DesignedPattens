#include "N95.h"

N95::N95()
{
	cout << "生产一部N95" << endl;
}

N95::~N95()
{
}

bool N95::MakeCall(const string & number) const
{
	cout << "我用的是N95， 我拨打的号码是：" << number << endl;
	return true;
}
