#include "N85.h"

N85::N85()
{
	cout << "����һ��N85" << endl;
}

N85::~N85()
{
}

bool N85::MakeCall(const string & number) const
{
	cout << "���õ���N85�� �Ҳ���ĺ����ǣ�" << number << endl;
	return true;
}
