#pragma once
#include "ISingleton.h"

class SingletonInstance:public ISingleton<SingletonInstance>
{
private:
	SingletonInstance() {} ;
	~SingletonInstance() {};
	friend ISingleton<SingletonInstance>;
	SingletonInstance(const SingletonInstance&) {}
	SingletonInstance& operator=(const SingletonInstance) {};
};