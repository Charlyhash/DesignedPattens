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
		��һЩ���������澲̬�ֲ������ж���ͨ��һ��ȫ�ֵı�־λ��¼
		�ñ����Ƿ��Ѿ���ʼ���˵ġ�
		bool flag = false;
		if (!flag)
		{
			flag = true;
			staticVar = initStatic();
		}
		��һ���̼߳��flag������if��֧�󣬵ڶ����߳̿��ܱ�������Ҳ����if��֧������
		�����̶߳���Ա�����ʼ�������ʹ��ָ�룬���ڶ�ָ����и�ֵ֮ǰʹ������֤
		ͬһʱ��ֻ��һ���̶߳�ָ����г�ʼ����ͬʱ�������ܿ��ǣ�ÿ�η���ʵ��ǰ�ȼ��
		ָ��ʱ���Ѿ���ʼ�����Ա���ÿ�ζ�Singleton�ķ��ʶ���Ҫ��������Ŀ��ơ�
		*/
		if (instance_ == NULL)
		{
			mtx.lock();
			if (instance_ == NULL)
			{
				instance_ = new T;
				//�������ʱ����ע�ắ��
				/*
				��֤����Щʵ���ܹ��ڳ����˳�ǰ��ȷ��������
				�ú���������Ҳ�ܱ�֤�󱻴�����ʵ�����ȱ�����
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
	ʹ��volatile�ؼ��֣�
	new�������Ϊ�����ڴ棬���ù��죬Ϊָ�븳ֵ3�������캯��
	SingletonInstance pInstance = new SingletonInstan();
	��ֳ�3����
	1 SingletonInstance pHeap = __new(sizeof(SingletonInstance));
	2 pHeap->SingletonInstance::SingletonInstance();
	3 SingletonInstance pInstance = pHeap;
	��ʱΪ���Ż��Ŀ��ǣ�����һ���͵������ϲ�Ϊͬһ����
	1 SingletonInstance pInstance = __new(sizeof(SingletonInstance));
	2 pInstance->SingletonInstance::SingletonInstance();
	�������ܵ�������һ���߳�����ڴ���䣬�л�����һ���߳��ٴη���pInstanceʱ
	�Ѿ���ֵ�����Ƿ��ص���һ���������Ķ����������volatile�ؼ��֣���ʾ�ñ���
	���ܻ�ı䣬ÿ�ζ��������Ҫ���ڴ���ȡ������ֵ��������ֹ��������ָ��˳���
	������
	*/
	static T* volatile instance_;
};

template<typename T>
T* volatile Singleton<T>::instance_ = NULL;
template<typename T>
mutex Singleton<T>::mtx;//mutex�ĳ�ʼ��

#endif // __SINGLETON_THREAD_SAFE_H__
