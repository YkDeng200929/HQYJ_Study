#include <iostream>

using namespace std;

class A
{
    public:
        void show()
        {
            cout << "show" << i << endl;
        }
        static void staticshow()   // 静态成员函数
        {
            cout << "static show" << i << endl;
        }

        static int i;
};

int A::i = 20;        // 静态成员的初始化必须写到类外

int main(void)
{
    cout << A::i << endl;
    A a;
    a.i = 80;
    cout << a.i << endl;
    cout << A::i << endl;
    A::staticshow(); // 静态成员函数可以通过<类名>::<静态函数函数名>的方式调用函数
//  A::show;         // 会报错 vscode下没报错
                     // error: invalid use of non-static member function ‘void A::show()

    return 0;
}