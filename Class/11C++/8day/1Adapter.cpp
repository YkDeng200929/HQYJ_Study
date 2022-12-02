#include <iostream>

using namespace std;

class PowerTarget
{
public:
    virtual ~PowerTarget() {;}
    virtual int GetPower110v() = 0;
};

class Outlet    // 现有接口
{
public:
    virtual ~Outlet() {;}
    virtual int GetPower220v()
    {
        return 220;
    }
};

class Adapter : public PowerTarget  // 对象模式
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

class Adapter2 : public PowerTarget, private Outlet  // 类模式
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
        // 对象模式
        /*
        Outlet *outlet = new Outlet;
        Adapter *adapter = new Adapter(outlet);
        cout << "输出电压: " << adapter->GetPower110v() << endl;

        delete outlet;
        delete adapter;
        outlet = NULL;
        adapter = NULL;
        */
    }

    {
        // 类模式
        PowerTarget *user = new Adapter2;
        cout << "输出电压: " << user->GetPower110v() << endl;

        delete user;
        user = NULL;
    }

    return 0;
}