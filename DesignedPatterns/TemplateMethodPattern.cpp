#include <iostream>
using namespace std;

template<typename T>
class CafeineBeverge
{
public:
	void PrepareRecipe()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddCondiments();
	}

	void BoilWater() { cout << "��ˮ���" << endl; }
	void Brew() { static_cast<T*>(this)->Brew(); }
	void PourInCup() { cout << "�ѿ��ȵ�����������" << endl; }
	void AddCondiments() { static_cast<T*>(this)->AddCondiments(); }
};

class Coffee :public CafeineBeverge<Coffee>
{
public:
	void Brew() { cout << "�÷�ˮ���ݿ���" << endl; }
	void AddCondiments() { cout << "���Ǻ�ţ��" << endl; }
};

class Tea :public CafeineBeverge<Tea>
{
public:
	void Brew() { cout << "�÷�ˮ���ݲ�Ҷ" << endl; }
	void AddCondiments() { cout << "������" << endl; }
};

int main()
{
	cout << "�屭���ȣ�" << endl;
	Coffee c;
	c.PrepareRecipe();
	cout << endl;
	cout << "�屭�裺" << endl;
	Tea t;
	t.PrepareRecipe();

	return 0;
}
