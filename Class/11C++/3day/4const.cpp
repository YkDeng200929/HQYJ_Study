#include <iostream>

using namespace std;

class Num
{
    public:
    Num(int i, int k) : i(i), k(k)
    {
    }

    void show()
    {
        cout << "no const show" << endl;
        // k = 88;报错
        cout << i << endl;
        cout << k << endl;
    }

    void show() const
    {
        cout << "const show" << endl;
        // k = 88; 报错
        cout << i << endl;
        cout << k << endl;
    }

    int i;
    const int k;
};


int main(void)
{
    Num number(2, 3);
    number.show();
    const Num number2(3, 4);
    number2.show();
    // number.k = 88; 报错
    // Num::k = 99; 报错
    // number2.k = 88; 报错

    return 0;  
}