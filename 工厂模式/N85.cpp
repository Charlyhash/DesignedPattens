#include "N85.h"

N85::N85()
{
	cout << "����һ��N85" << endl;
}

N85::~N85(){}

bool N85::MakeCall(const string &number) const
{
	cout << "����N85�� ��Ҫ����ĵ绰�ǣ�" << number << endl;
	return true;
}
