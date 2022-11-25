#include <iostream>

using namespace std;

class A
{
    public:
        void show()
        {
            cout << "show" << i << endl;
        }
        static void staticshow()
        {
            cout << "static show" << i << endl;
        }

        static int i;
};

int A::i = 20; // 静态成员的初始化必须写到类外

int main(void)
{
    cout << A::i << endl;
    A a;
    a.i = 80;
    cout << a.i << endl;
    cout << A::i << endl;
    A::staticshow(); // 只用静态的东西才能直接使用类名加域操作符调用
    //A::show; 会报错

    return 0;
}