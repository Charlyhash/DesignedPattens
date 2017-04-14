/*
C++实现单例模式
通过一个静态函数Instance返回局部静态变量。
*/

#pragma once
#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton& Instance()
	{
		//静态变量只初始化一次，初始化后直到程序结束都一直存在
		//静态局部变量只对定义自己的函数体可见。
		static Singleton singleton;
		return singleton;
	}
private:
	Singleton() {};
	Singleton(Singleton const&) {};
	Singleton& operator=(Singleton const&) {};
	~Singleton() {};
};
