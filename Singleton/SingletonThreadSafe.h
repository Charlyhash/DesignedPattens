#ifndef __SINGLETON_THREAD_SAFE_H__
#define __SINGLETON_THREAD_SAFE_H__

#include <iostream>
#include <mutex>

using namespace std;

template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		Init();
		return *instance_;
	}

private:
	static void Init()
	{
		/*
		在一些编译器里面静态局部变量判断是通过一个全局的标志位记录
		该变量是否已经初始化了的。
		bool flag = false;
		if (!flag)
		{
			flag = true;
			staticVar = initStatic();
		}
		当一个线程检测flag并进入if分支后，第二个线程可能被启动，也进入if分支。这样
		两个线程都会对变量初始化。这里，使用指针，并在对指针进行赋值之前使用锁保证
		同一时间只有一个线程对指针进行初始化。同时基于性能考虑，每次访问实例前先检查
		指针时候已经初始化，以避免每次对Singleton的访问都需要请求对锁的控制。
		*/
		if (instance_ == NULL)
		{
			mtx.lock();
			if (instance_ == NULL)
			{
				instance_ = new T;
				//程序结束时调用注册函数
				/*
				保证了这些实例能够在程序退出前正确地析构。
				该函数的特性也能保证后被创建的实例首先被析构
				*/
				atexit(Destory);
			}
			mtx.unlock();
		}
	}

	static void Destory()
	{
		if (instance_ != nullptr)
			delete instance_;
	}
	Singleton(const Singleton& other) {};
	Singleton& operator=(const Singleton& other) {};
	Singleton() {};
	~Singleton() {};

private:
	static mutex mtx;
	/*
	使用volatile关键字：
	new运算符分为分配内存，调用构造，为指针赋值3步。构造函数
	SingletonInstance pInstance = new SingletonInstan();
	会分成3步：
	1 SingletonInstance pHeap = __new(sizeof(SingletonInstance));
	2 pHeap->SingletonInstance::SingletonInstance();
	3 SingletonInstance pInstance = pHeap;
	有时为了优化的考虑，将第一步和第三步合并为同一步。
	1 SingletonInstance pInstance = __new(sizeof(SingletonInstance));
	2 pInstance->SingletonInstance::SingletonInstance();
	这样可能导致其中一个线程完成内存分配，切换到另一个线程再次访问pInstance时
	已经赋值，但是返回的是一个不完整的对象。这里添加volatile关键字，表示该变量
	可能会改变，每次对其操作都要从内存中取得它的值，可以阻止编译器对指令顺序的
	调整。
	*/
	static T* volatile instance_;
};

template<typename T>
T* volatile Singleton<T>::instance_ = NULL;
template<typename T>
mutex Singleton<T>::mtx;//mutex的初始化

#endif // __SINGLETON_THREAD_SAFE_H__
