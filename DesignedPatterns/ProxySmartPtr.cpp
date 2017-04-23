#include <iostream>
using namespace std;

template<typename T>
class SmartPtr
{
private:
	T* pointee;
	size_t* count;
	void decr_count()
	{
		if (--*count == 0)
		{
			delete count;
			delete pointee;
		}
	}
public:
	SmartPtr(T* p = 0):pointee(p), count(new size_t(1)){}
	SmartPtr(const SmartPtr &rhs) :pointee(rhs.pointee), count(rhs.count) { ++*count; }
	~SmartPtr() { decr_count(); }
	SmartPtr& operator=(const SmartPtr& rhs)
	{
		++*(rhs.count);;
		decr_count();
		pointee = rhs.pointee;
		count = rhs.count;
		return *this;
	}
	SmartPtr& operator= (T* ptr) //ÖØÔØ¸³Öµ²Ù×÷·û
	{
		if (pointee == ptr) return *this;
		decr_count();
		pointee = ptr;
		count = new size_t(1);
		return *this;
	}
	T* operator->() { return pointee; }
	const T* operator->() const { return pointee; }
	T &operator*() { return *pointee; }
	const T& operator*() const { return pointee; }
	size_t RefCount()
	{
		return *count;
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
	SmartPtr<Test> p(new Test());
	cout << p.RefCount() << endl;
	SmartPtr<Test> p2(p);
	cout << p.RefCount() << endl;
	cout << p2.RefCount() << endl;
	SmartPtr<Test> p3;
	p3 = p;

	cout << p.RefCount() << endl;
	cout << p2.RefCount() << endl;
	cout << p3.RefCount() << endl;

	return 0;
}