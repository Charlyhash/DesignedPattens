#include "Builder.h"
#include <iostream>

using namespace std;

int main()
{
	KFCBuilder kfc;//想吃kfc
	Director director(&kfc);
	director.Create();//创造一个kfc

	return 0;
}