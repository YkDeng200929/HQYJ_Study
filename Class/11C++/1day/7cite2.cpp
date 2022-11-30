#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int &cite(int &num)
{
    static int num2 = 80;
    return num2;
}

int main(void)
{
    int a = 99;
    int b = 1;
    cout << "a: " << a << " b: " << b << endl;
    swap(a, b);
    cout << "a: " << a << " b: " << b << endl;

    int ret = cite(b);
    int c;
    cite(b) = c;

    cout << "ret: " << ret << "c: " << c << endl;

    return 0;
}