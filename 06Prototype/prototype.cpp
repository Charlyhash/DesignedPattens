#include "prototype.h"
#include <iostream>

using namespace std;

Prototype::Prototype():number(100)
{
	cout << "---Prototype constructor..." << endl;
}

ConcretePrototype::ConcretePrototype()
{
	cout << "---concretePrototype..." << endl;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &cp)
{
	cout << "---concrete prototype copy..." << endl;
}

Prototype * ConcretePrototype::Clone() const
{
	cout << "---clone..." << endl;
	return new ConcretePrototype(*this);
}
