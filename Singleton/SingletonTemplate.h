/*
C++实现可重用的单例模式
通过一个静态函数Instance返回局部静态变量。
*/

#pragma once
#include <iostream>

using namespace std;

template<typename T>
class ISingleton
{
public:
	static T& Instance()
	{
		//静态变量只初始化一次，初始化后直到程序结束都一直存在
		//静态局部变量只对定义自己的函数体可见。
		static T s_instance;
		return s_instance;
	}
	ISingleton(ISingleton const&) = delete;
	ISingleton& operator=(ISingleton const&) = delete;
protected:
	ISingleton() {};		//类可以从模版继承
	virtual ~ISingleton() {};
	
};


