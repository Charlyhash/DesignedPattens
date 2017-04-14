#include "prototype.h"
#include <iostream>

using namespace std;

int main()
{
	//克隆操作
	Prototype *p1 = new ConcretePrototype();
	cout << "before clone:" << p1->number << endl;
	Prototype *p2 = p1->Clone();
	cout << "clone:" << p2->number << endl;
	p2->number = 200;
	cout << "origin:" << p1->number << endl;
	cout << "clone:" << p2->number << endl;

	cout << "--------------------------" << endl;
	//拷贝构造
	ConcretePrototype p3;
	ConcretePrototype p4 = p3;

	delete p1;
	delete p2;
	return 0;
}