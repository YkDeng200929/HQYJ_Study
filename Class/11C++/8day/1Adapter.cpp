#include <iostream>

using namespace std;

class PowerTarget
{
public:
    virtual ~PowerTarget() {;}
    virtual int GetPower110v() = 0;
};

class Outlet    // ���нӿ�
{
public:
    virtual ~Outlet() {;}
    virtual int GetPower220v()
    {
        return 220;
    }
};

class Adapter : public PowerTarget  // ����ģʽ
{
public:
    Adapter(Outlet *outlet) : outlet(outlet) {;}
    virtual int GetPower110v()
    {
        return outlet->GetPower220v() / 2;
    }
private:
    Outlet *outlet;
};

class Adapter2 : public PowerTarget, private Outlet  // ��ģʽ
{
public:
    virtual int GetPower110v()
    {
        return GetPower220v() / 2;
    }
};

int main(void)
{
    {
        // ����ģʽ
        /*
        Outlet *outlet = new Outlet;
        Adapter *adapter = new Adapter(outlet);
        cout << "�����ѹ: " << adapter->GetPower110v() << endl;

        delete outlet;
        delete adapter;
        outlet = NULL;
        adapter = NULL;
        */
    }

    {
        // ��ģʽ
        PowerTarget *user = new Adapter2;
        cout << "�����ѹ: " << user->GetPower110v() << endl;

        delete user;
        user = NULL;
    }

    return 0;
}