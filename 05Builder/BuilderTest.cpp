#include "Builder.h"
#include <iostream>

using namespace std;

int main()
{
	KFCBuilder kfc;//���kfc
	Director director(&kfc);
	director.Create();//����һ��kfc

	return 0;
}