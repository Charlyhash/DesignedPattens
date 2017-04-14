/*
C++ʵ�ֵ���ģʽ
ͨ��һ����̬����Instance���ؾֲ���̬������
*/

#pragma once
#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton& Instance()
	{
		//��̬����ֻ��ʼ��һ�Σ���ʼ����ֱ�����������һֱ����
		//��̬�ֲ�����ֻ�Զ����Լ��ĺ�����ɼ���
		static Singleton singleton;
		return singleton;
	}
private:
	Singleton() {};
	Singleton(Singleton const&) {};
	Singleton& operator=(Singleton const&) {};
	~Singleton() {};
};
