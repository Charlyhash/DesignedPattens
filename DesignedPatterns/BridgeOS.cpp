#include <iostream>
using namespace std;


/*
����װ����ϵͳ���ж������õļ������ͬ��Ҳ�ж�����ϵͳ��
��������Ž�ģʽ�أ����Խ�����ϵͳ�ͼ�����ֱ���������
�����Ǹ��Է�չ���������ǵ���϶ȡ���Ȼ�ˣ�����֮���б�׼
�Ľӿڡ�������ƣ������Ƕ��ڼ���������ǲ���ϵͳ���Ƿǳ������ġ�

*/
//����ϵͳ��
class OS
{
public:
	virtual void InstallOS_Imp(){}
};

class WindowOS :public OS
{
public:
	void InstallOS_Imp()
	{
		cout << "��װwindows����ϵͳ" << endl;
	}
};

class LinuxOS :public OS
{
public:
	void InstallOS_Imp()
	{
		cout << "��װLinux����ϵͳ" << endl;
	}
};

class UnixOS :public OS
{
public:
	void InstallOS_Imp()
	{
		cout << "��װUnix����ϵͳ" << endl;
	}
};


//�������
class Computer
{
public:
	virtual void InstallOS(OS* os){}
};

class DellCompter :public Computer
{
public:
	void InstallOS(OS* os)
	{
		os->InstallOS_Imp();
	}
};

class AppleCompter : public Computer
{
public:
	void InstallOS(OS* os)
	{
		os->InstallOS_Imp();
	}
};

class HPCompter : public Computer
{
public:
	void InstallOS(OS* os)
	{
		os->InstallOS_Imp();
	}
};
int main()
{
	OS *os1 = new WindowOS();
	OS *os2 = new LinuxOS();
	Computer *c = new AppleCompter();
	c->InstallOS(os1);
	c->InstallOS(os2);

	delete os1; os1 = nullptr;
	delete os2; os2 = nullptr;
	delete c; c = nullptr;

	return 0;
}