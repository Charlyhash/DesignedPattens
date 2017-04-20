#include <iostream>
#include <list>
#include <string>
#include <set>
using namespace std;

//观察者
class Observer
{
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void Update() {}
};

//博客
class Blog
{
private:
	set<Observer*> m_observers;
protected:
    string m_status;
public:
    Blog(){}
    virtual ~Blog(){}
    void Attach(Observer *observer) { m_observers.insert(observer);}
    void Remove(Observer *observer) { m_observers.erase(observer);}
    void Notify()
    {
		for (auto iter : m_observers)
			iter->Update();
    }
    virtual void SetStatus(string s) {m_status = s;}
    virtual string GetStatus() {return m_status;}
};

//具体博客类
class BlogCSDN:public Blog
{
private:
    string m_name;
public:
    BlogCSDN(string name):m_name(name){}
    ~BlogCSDN(){}
    void SetStatus(string s) {m_status = "CSDN通知:" + m_name + s;}
    string GetStatus() {return m_status;}
};

class ObserverBlog:public Observer
{
private:
    string m_name;
    Blog *m_blog;
public:
    ObserverBlog(string name, Blog *blog):m_name(name), m_blog(blog){}
    ~ObserverBlog(){}
    void Update()
    {
        string status = m_blog->GetStatus();
        cout << m_name << "---------" << status << endl;
    }
};

int main()
{
    Blog *blog = new BlogCSDN("aabbcc");
    Observer *observer1 = new ObserverBlog("d", blog);
    blog->Attach(observer1);
    blog->SetStatus("发布设计模式-observer");
    blog->Notify();
    delete blog; delete observer1;

    return 0;
}

