#include <iostream>

using namespace std;

class A
{
public:
    virtual void fun1()
    {
        cout << "A func1" << endl;
    }

    virtual void fun2()
    {
        cout << "A func2" << endl;
    }

    virtual void fun3()
    {
        cout << "A func3" << endl;
    }
};

typedef void (*pnf)();

int main(void)
{
    A a;
    cout << "指向虚函数表指针的地址: " << (long *)&a << endl;
    cout << "虚函数表的地址: " << (long *)(long *)&a << endl;
    cout << "虚函数表内第二个元素的地址: " << (long *)*(long *)&a + 1 << endl;
    cout << "虚函数表内第三个元素的值: " << (long *)*((long *)*(long *)&a + 2) << endl;

    pnf p = (pnf)*((long *)*(long *)&a + 2); // 函数指针指向了fun3
    p();// 所以p() 就相当于调用了fun3

    return 0;
}