#include <iostream>

using namespace std;

class Soldier
{
public:
    virtual ~Soldier(void){;}
    virtual void Move(void) = 0;
    virtual void Attack(void) = 0;
}; // end class Soldier

class RedSoldier : public Soldier
{
public:
    virtual void Move(void)
    {
        cout << "Red Soldier Move" << endl;
    }

    virtual void Attack(void)
    {
        cout << "Red Soldier Attack" << endl;
    }
}; // end class RedSolier

class BlueSoldier : public Soldier
{
public:
    virtual void Move(void)
    {
        cout << "Blue Soldier Move" << endl;
    }

    virtual void Attack(void)
    {
        cout << "Blue Soldier Attack" << endl;
    }
}; // end class BlueSoldier

// version1: 简单工厂, 不满足开闭原则
class SimpleFactory   
{
public:
    static Soldier* ProductSoldier(const string& color)
    {
        if (color == "red")
        {
            return new RedSoldier;
        }
        else if (color == "blue")
        {
            return new BlueSoldier;
        }
        else
        {
            cout << "Input error: " << color << endl;
            return NULL;
        }
    }
}; // end class Factory

// version2: 抽象工厂
class Factory   // 抽象工厂
{
public:
    virtual ~Factory(void){;}
    virtual Soldier* ProductSoldier(void) = 0;
};

class RedFactory : public Factory    // 红方工厂
{
public:
    virtual Soldier* ProductSoldier(void)
    {
        return new RedSoldier;
    }
};

class BlueFactory : public Factory   // 蓝方工厂
{
public:
    virtual Soldier* ProductSoldier(void)
    {
        return new BlueSoldier;
    }
};

int main(void)
{
    cout << "简单工厂: " << endl;
    Soldier* soldier = SimpleFactory::ProductSoldier("red");

    soldier->Move();
    soldier->Attack();

    delete soldier;

    cout << "抽象工厂: " << endl;
    Factory* redFactory = new RedFactory;
    Factory* blueFactory = new BlueFactory;    

    Soldier* redSoldier = redFactory->ProductSoldier();
    Soldier* blueSoldier = blueFactory->ProductSoldier();

    redSoldier->Move();
    redSoldier->Attack();
    blueSoldier->Move();
    blueSoldier->Attack();

    delete redFactory;
    delete blueFactory;
    delete redSoldier;
    delete blueSoldier;

    return 0;
}