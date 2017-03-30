#include "N96.h"

N96::N96(){
	cout << "生产一部N96" << endl;
}

N96::~N96() {}

bool N96::MakeCall(const string &number) const
{
	cout << "我在用N96，拨打号码是：" << number << endl;
	return true;
}