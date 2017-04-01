#include "SingletonThreadSafe.h"
#include <thread>
#include <iostream>

using namespace std;

class ApplicationImpl
{
public :
	ApplicationImpl()
	{
		cout << "ApplicationImpl..." << endl;
	}

	~ApplicationImpl()
	{
		cout << "~ApplicationImpl..." << endl;
	}

	void Run()
	{
		cout << "Run..." << endl;
	}
};

typedef Singleton<ApplicationImpl> Application;

void rountine()
{
	Application::GetInstance().Run();
}

int main()
{
	Application::GetInstance().Run();
	/*
	C++ 11����һ���߳�Ϊ��
	thread tid(func, arg1, arg2, ...)������funcΪҪִ�еĺ�����
	arg1, arg2, ...Ϊ��Ҫ���ݵĲ���
	*/
	thread tid(rountine);//����һ���߳�
	Application::GetInstance().Run();
	tid.join();

	return 0;
}