/*
C++ʵ�ֿ����õĵ���ģʽ
ͨ��һ����̬����Instance���ؾֲ���̬������
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
		//��̬����ֻ��ʼ��һ�Σ���ʼ����ֱ�����������һֱ����
		//��̬�ֲ�����ֻ�Զ����Լ��ĺ�����ɼ���
		static T s_instance;
		return s_instance;
	}
	ISingleton(ISingleton const&) = delete;
	ISingleton& operator=(ISingleton const&) = delete;
protected:
	ISingleton() {};		//����Դ�ģ��̳�
	virtual ~ISingleton() {};
	
};


