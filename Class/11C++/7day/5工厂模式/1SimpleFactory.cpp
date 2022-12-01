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

// version1: �򵥹���, �����㿪��ԭ��
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

// version2: ���󹤳�
class Factory   // ���󹤳�
{
public:
    virtual ~Factory(void){;}
    virtual Soldier* ProductSoldier(void) = 0;
};

class RedFactory : public Factory    // �췽����
{
public:
    virtual Soldier* ProductSoldier(void)
    {
        return new RedSoldier;
    }
};

class BlueFactory : public Factory   // ��������
{
public:
    virtual Soldier* ProductSoldier(void)
    {
        return new BlueSoldier;
    }
};

int main(void)
{
    cout << "�򵥹���: " << endl;
    Soldier* soldier = SimpleFactory::ProductSoldier("red");

    soldier->Move();
    soldier->Attack();

    delete soldier;

    cout << "���󹤳�: " << endl;
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