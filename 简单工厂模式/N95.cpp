#include "N95.h"

N95::N95()
{
	cout << "����һ��N95" << endl;
}

N95::~N95()
{
}

bool N95::MakeCall(const string & number) const
{
	cout << "���õ���N95�� �Ҳ���ĺ����ǣ�" << number << endl;
	return true;
}
