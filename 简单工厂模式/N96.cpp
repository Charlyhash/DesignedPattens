#include "N96.h"

N96::N96(){
	cout << "����һ��N96" << endl;
}

N96::~N96() {}

bool N96::MakeCall(const string &number) const
{
	cout << "������N96����������ǣ�" << number << endl;
	return true;
}