#include <iostream>
#include <vector>
using namespace std;

//保存的信息类
class Memento
{
public:
    int m_vitality; //生命值
    int m_attack; //进攻值
    int m_defense; //防守值

public:
    Memento(int vitality, int attack, int defense):m_vitality(vitality), m_attack(attack), m_defense(defense){}

    Memento& operator=(const Memento &m)
    {
        m_vitality = m.m_vitality;
        m_attack = m.m_attack;
        m_defense = m.m_defense;

        return *this;
    }
};

//游戏角色
class GameRole
{
private:
    int m_vitality;
    int m_attack;
    int m_defense;
public:
    GameRole():m_vitality(100), m_attack(100), m_defense(100){}
    Memento Save() //保存进度
    {
        Memento memento(m_vitality, m_attack, m_defense);
        return memento;
    }
    void Load(Memento m)
    {
        m_vitality = m.m_vitality;
        m_attack = m.m_attack;
        m_defense = m.m_defense;
    }

    void Show()
    {
        cout << "vality:" << m_vitality << ", attack: " << m_attack
            << ", defense: " << m_defense << endl;
    }

    void Attack()
    {
        m_vitality -=10;
        m_attack -= 10;
        m_defense -= 10;
    }
};

//保存进度类
class Caretake
{
private:
    vector<Memento> m_vecMemento;

public:
    Caretake() {}
    void Save(Memento m) { m_vecMemento.push_back(m);}
    Memento Load(int state) { return m_vecMemento[state];}
};

//客户端调用
int main()
{
    Caretake c;
    GameRole role;
    role.Show();
    c.Save(role.Save());
    role.Attack();
    role.Attack();
    role.Show();
    role.Load(c.Load(0));
    role.Show();

    return 0;
}
