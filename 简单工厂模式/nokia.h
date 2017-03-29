#pragma once
/*
简单工厂模式：用一个单独的类来创建实例，也就是说，这个类就是
一个工厂，通过静态工厂统一管理对象的创建。静态工厂方法通过传
入的参数来判断创建哪个产品的实例。
*/

#include <iostream>
#include <string>

using namespace std;

class Nokia
{
public:
	Nokia();
	virtual ~Nokia();
	virtual bool MakeCall(const string &number) const = 0;
};

