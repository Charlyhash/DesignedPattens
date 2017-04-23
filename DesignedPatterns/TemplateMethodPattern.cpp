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

	void BoilWater() { cout << "°ÑË®Öó·Ð" << endl; }
	void Brew() { static_cast<T*>(this)->Brew(); }
	void PourInCup() { cout << "°Ñ¿§·Èµ¹½ø±»×ÓÀïÃæ" << endl; }
	void AddCondiments() { static_cast<T*>(this)->AddCondiments(); }
};

class Coffee :public CafeineBeverge<Coffee>
{
public:
	void Brew() { cout << "ÓÃ·ÐË®³åÅÝ¿§·È" << endl; }
	void AddCondiments() { cout << "¼ÓÌÇºÍÅ£ÄÌ" << endl; }
};

class Tea :public CafeineBeverge<Tea>
{
public:
	void Brew() { cout << "ÓÃ·ÐË®½þÅÝ²èÒ¶" << endl; }
	void AddCondiments() { cout << "¼ÓÄûÃÊ" << endl; }
};

int main()
{
	cout << "³å±­¿§·È£º" << endl;
	Coffee c;
	c.PrepareRecipe();
	cout << endl;
	cout << "³å±­²è£º" << endl;
	Tea t;
	t.PrepareRecipe();

	return 0;
}
