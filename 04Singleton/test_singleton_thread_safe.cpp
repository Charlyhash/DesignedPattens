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
	C++ 11创建一个线程为：
	thread tid(func, arg1, arg2, ...)，其中func为要执行的函数，
	arg1, arg2, ...为需要传递的参数
	*/
	thread tid(rountine);//创建一个线程
	Application::GetInstance().Run();
	tid.join();

	return 0;
}