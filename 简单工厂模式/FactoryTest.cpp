#include "NokiaSimpleFactory.h"
//�൱�ڿͻ���
int main()
{
	Nokia* nokia;
	string modelName = "N85";
	//���ݴ���Ĳ������ж��������ֲ�Ʒ
	nokia = NokiaSimpleFactory::CreateNokia(modelName);//����һ��N85
	nokia->MakeCall("1234567");
	delete nokia; nokia = nullptr;

	return 0;
}