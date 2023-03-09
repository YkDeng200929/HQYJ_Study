#include <iostream>

using namespace std;

// 函数重载
void fun(int a)
{
    cout << a << endl;
}

void fun(string str)
{
    cout << str << endl;
}

void fun(int a, int b)
{
    cout << a + b << endl;
}

int main(void)
{
    fun(3);
    fun("ykdeng");
    fun(4, 6);

    return 0;
}