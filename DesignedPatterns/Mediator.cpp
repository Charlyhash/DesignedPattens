#include <iostream>
#include <string>
using namespace std;

class Mediator;

//抽象人
class Person
{
protected:
    Mediator *m_mdiator;//中介
public:
    virtual void SetMediator(Mediator *m){}//设置中介者
    virtual void SendMessage(string msg){} //向中介者发送消息
    virtual void GetMessage(string msg){} //从中介者获取消息

    virtual ~Person(){}
};

//抽象中介者
class Mediator
{
public:
    virtual void Send(string msg, Person *p){}
    virtual void SetA(Person *A){} //设置其中一方
    virtual void SetB(Person *B){}
};

//租房者
class Renter:public Person
{
public:
    ~Renter(){}

    void SetMediator(Mediator *m) {m_mdiator = m;}
    void SendMessage(string msg) {m_mdiator->Send(msg, this);}
    void GetMessage(string msg) {cout << "租房者收到信息：" << msg << endl;}
};

//房东
class LandLoad:public Person
{
public:
    void SetMediator(Mediator* m) {m_mdiator = m;}
    void SendMessage(string msg) {m_mdiator->Send(msg, this);}
    void GetMessage(string msg) {cout << "房东收到信息："<< msg << endl;}
};

//房屋中介
class HouseMediator:public Mediator
{
private:
    Person *m_A;
    Person *m_B;

public:
    HouseMediator():m_A(NULL), m_B(NULL){}
    void SetA(Person *A){m_A = A;}
    void SetB(Person *B){m_B = B;}
    void Send(string message, Person *person)
    {
        if (person == m_A)
            m_B->GetMessage(message);
        else
            m_A->GetMessage(message);
    }
};

int main()
{
    Mediator *mediator = new HouseMediator();
    Person *person1 = new Renter();
    Person *person2 = new LandLoad();
    mediator->SetA(person1);
    mediator->SetB(person2);
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);
    person1->SendMessage("我想在南京路附近租一套房子，价格800元/月");
    person2->SendMessage("出租房子：南京路100号，70平米，1000元/月");

    delete person1; delete person2; delete mediator;

    return 0;
}
