#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

//原型类，有一个clone接口
class Prototype
{
public:
	virtual ~Prototype() {}
	virtual Prototype* Clone() const = 0;
	int number;
protected:
	Prototype();
};
//具体实现类，实现一个clone自身的操作
class ConcretePrototype :public Prototype
{
public:
	ConcretePrototype();
	ConcretePrototype(const ConcretePrototype &cp);
	~ConcretePrototype() {}
	Prototype* Clone() const;

};

#endif