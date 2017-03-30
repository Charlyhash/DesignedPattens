#include "AbstractFactory.h"



AbstractFactory::AbstractFactory():
	pA1(NULL),pA2(NULL),pB1(NULL),pB2(NULL)
{

}


AbstractFactory::~AbstractFactory()
{
	if (pA1)
		delete pA1;
	if (pA2)
		delete pA2;
	if (pB1)
		delete pB1;
	if (pB2)
		delete pB2;
}
