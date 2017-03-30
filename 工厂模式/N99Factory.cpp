#include "N99Factory.h"

N99Factory::N99Factory(){}

N99Factory::~N99Factory(){}

Nokia* N99Factory::CreateNokia()
{
	return new N99();
}