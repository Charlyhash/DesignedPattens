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

/* 输出
创建一部N85
我是N85， 我要拨打的电话是：1234567
*/