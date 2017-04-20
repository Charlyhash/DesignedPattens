#include <iostream>
using namespace std;


/*
考虑装操作系统，有多种配置的计算机，同样也有多款操作系统。
如何运用桥接模式呢？可以将操作系统和计算机分别抽象出来，
让它们各自发展，减少它们的耦合度。当然了，两者之间有标准
的接口。这样设计，不论是对于计算机，还是操作系统都是非常有利的。

*/
//操作系统类
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
		cout << "安装windows操作系统" << endl;
	}
};

class LinuxOS :public OS
{
public:
	void InstallOS_Imp()
	{
		cout << "安装Linux操作系统" << endl;
	}
};

class UnixOS :public OS
{
public:
	void InstallOS_Imp()
	{
		cout << "安装Unix操作系统" << endl;
	}
};


//计算机类
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