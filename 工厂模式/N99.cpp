#include "N99.h"

N99::N99()
{
	cout << "����һ��N99" << endl;
}

N99::~N99(){}

bool N99::MakeCall(const string &number) const
{
	cout << "����N99�� ��Ҫ����ĵ绰�ǣ�" << number << endl;
	return true;
}
