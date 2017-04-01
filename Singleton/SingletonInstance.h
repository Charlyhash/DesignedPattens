#pragma once
#include "SingletonTemplate.h"

class SingletonInstance:public ISingleton<SingletonInstance>
{
private:
	SingletonInstance() {} ;
	~SingletonInstance() {};
	friend ISingleton<SingletonInstance>;
	SingletonInstance(const SingletonInstance&) {}
	SingletonInstance& operator=(const SingletonInstance) {};
};