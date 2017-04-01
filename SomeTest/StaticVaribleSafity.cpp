#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;

mutex mtx;

class Test {
public:
	Test()
	{
	}

	void Run()
	{
		static int i = 1;
		cout << "constructor start" << endl;
		for (int k = 0; k < 5; ++k)
			cout << ++i << endl;
		cout << "constructor end " << endl;
	}
};

void func(int id)
{
	
	Sleep(3000);
	static Test t;
	for (int k = 1; k < 5; ++k)
	{
		t.Run();
	}
}

int main()
{
	const int threadNumber = 4;
	thread tids[threadNumber];
	for (int i = 0; i < threadNumber; ++i)
		tids[i] = thread(func, i);

	for (int i = 0; i < threadNumber; ++i)
		tids[i].join();

	//cout << i << endl;
	return 0;

}