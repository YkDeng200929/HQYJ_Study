#include <iostream>

using namespace std;

class A
{
public:
    A(int data) : data(data) {;}
    int data;
};

int main(void)
{
    A num1(5);
    A num2(4);

    A tmp = num1;
    num1 = num2;
    num2 = tmp;

    cout << num1.data << endl;
    cout << num2.data << endl;

    return 0;
}