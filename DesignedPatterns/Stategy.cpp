#include <iostream>
#include <string>
using namespace std;

class WeaponBehavior
{
public:
	virtual void UseWeapon() = 0;
};

class AK47 : public WeaponBehavior
{
public:
	void UseWeapon() override
	{
		cout << "Use AK47 to shoot£¡" << endl;
	}
};

class Knife : public WeaponBehavior
{
public:
	void UseWeapon() override
	{
		cout << "Use knife to kill!" << endl;
	}
};

class Charater
{
protected:
	WeaponBehavior *weapon;
public:
	Charater()
	{
		weapon = nullptr;
	}
	void SetWeapon(WeaponBehavior *w)
	{
		weapon = w;
	}
	virtual  void fight() = 0;
};

class King:public Charater
{
public:
	void fight() override
	{
		cout << "The king:";
		if (weapon == nullptr)
		{
			cout << "You don't have a weapon! Please set Weapon first!" << endl;
		}
		else
			weapon->UseWeapon();
	}
};

int main()
{
	WeaponBehavior *ak47 = new AK47();
	WeaponBehavior *knife = new Knife();

	Charater *king = new King();

	king->fight();
	cout << endl;

	king->SetWeapon(ak47);
	king->fight();
	cout << endl;

	king->SetWeapon(knife);
	king->fight();
	cout << endl;

	if (king) { delete king; king = nullptr; }
	if (ak47) { delete ak47; ak47 = nullptr; }
	if (knife) {delete knife; knife = nullptr;}
	

	return 0;
}