#include "NokiaSimpleFactory.h"

NokiaSimpleFactory::NokiaSimpleFactory()
{
}

NokiaSimpleFactory::~NokiaSimpleFactory()
{
}

Nokia * NokiaSimpleFactory::CreateNokia(const string & model)
{
	if (model == "N96")
		return new N96();
	else if (model == "N95")
		return new N95();
	else if (model == "N85")
		return new N85();
	else
		cout << "û������ " << model << " �Ĺ���" << endl;

	return NULL;
}
