#include <iostream>
using namespace std;

template<typename T>
class AutoPtr
{
private:
	T* pointee;
public:
	explicit AutoPtr(T* p = nullptr) : pointee(p){}
	AutoPtr(AutoPtr<T>& rhs):pointee(rhs.release()){}
	~AutoPtr()
	{
		delete pointee;
	}
	T& operator*() const { return *pointee; }
	T* operator->() const { return pointee; }
	T* get() const { return pointee; }
	T* release()
	{
		T* oldPointee = pointee;
		pointee = nullptr;
		return oldPointee;
	}
	void reset(T* p = nullptr)
	{
		if (pointee != p)
		{
			delete pointee;
			pointee = p;
		}
	}
};

class Test
{
public:
	Test() { cout << "test()..." << endl; }
	~Test() { cout << "~test()..." << endl; }
};

int main()
{
	AutoPtr<Test> p(new Test()); //p��һ��ָ��Test���͵�ָ��
	AutoPtr<Test> q(p.release());//�����˳�����Զ�����

	return 0;
}