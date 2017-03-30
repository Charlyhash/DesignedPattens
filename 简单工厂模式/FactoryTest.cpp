#include "NokiaSimpleFactory.h"
//相当于客户端
int main()
{
	Nokia* nokia;
	string modelName = "N85";
	//根据传入的参数，判断生产哪种产品
	nokia = NokiaSimpleFactory::CreateNokia(modelName);//生产一部N85
	nokia->MakeCall("1234567");
	delete nokia; nokia = nullptr;

	return 0;
}