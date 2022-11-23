#include <iostream>

using namespace std;

void add(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0)
{
    cout << a + b + c + d + e << endl;
}

/*带占位参数的函数*/
void fun(int a, int b, int)
{
    cout << a + b << endl;
}

int main(void)
{
    add(5, 9);
    fun(20, 30, 0);

    return 0;
}