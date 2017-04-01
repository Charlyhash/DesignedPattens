#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

//ԭ���࣬��һ��clone�ӿ�
class Prototype
{
public:
	virtual ~Prototype() {}
	virtual Prototype* Clone() const = 0;
	int number;
protected:
	Prototype();
};
//����ʵ���࣬ʵ��һ��clone����Ĳ���
class ConcretePrototype :public Prototype
{
public:
	ConcretePrototype();
	ConcretePrototype(const ConcretePrototype &cp);
	~ConcretePrototype() {}
	Prototype* Clone() const;

};

#endif