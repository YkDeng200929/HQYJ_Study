#include <iostream>

/*引用*/
using namespace std;

int main(void)
{
    int a = 10;
    int *p = &a;

    cout << *p << endl;

    int &q = a; // 创建一个引用, 必须初始化
    // 且创建引用后不能解除绑定的引用
    // eg.
    // int b = 33;
    // &q = b; error
    //------------------

    cout << " q " << q << endl;

    q = 20;     // 给q引用的值复制
    cout << " a " << a << endl;

    return 0;
}