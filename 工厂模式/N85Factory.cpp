#include "N85Factory.h"

N85Factory::N85Factory(){}

N85Factory::~N85Factory(){}

Nokia* N85Factory::CreateNokia()
{
	return new N85();
}