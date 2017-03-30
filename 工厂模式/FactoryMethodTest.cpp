#include "FactoryMethod.h"
#include "nokia.h"
#include "N85Factory.h"
#include "N99Factory.h"

int main()
{
	FactoryMethod *fm = new N85Factory();
	Nokia* nokia = fm->CreateNokia();
	nokia->MakeCall("1234567");
	delete fm; fm = nullptr;
	delete nokia; nokia = nullptr;

	return 0;
}

/* ���
����һ��N85
����N85�� ��Ҫ����ĵ绰�ǣ�1234567
*/