#pragma once
/*
�򵥹���ģʽ����һ����������������ʵ����Ҳ����˵����������
һ��������ͨ����̬����ͳһ�������Ĵ�������̬��������ͨ����
��Ĳ������жϴ����ĸ���Ʒ��ʵ����
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

