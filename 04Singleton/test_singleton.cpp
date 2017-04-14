#include "SingletonTemplate.h"
#include "SingletonInstance.h"
#include <iostream>

using namespace std;

//extern int bbb;

int main()
{
	
	
	SingletonInstance::Instance();
	SingletonInstance::Instance();


	return 0;
}