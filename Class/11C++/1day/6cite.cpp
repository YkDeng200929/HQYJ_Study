#include <iostream>

/*引用*/
using namespace std;

int main(void)
{
    int a = 10;
    int *p = &a;

    cout << *p << endl;

    int &q = a; // 创建一个引用, 必须初始化

    cout << " q " << q << endl;

    q = 20;     // 给q引用的值复制
    cout << " a " << a << endl;

    return 0;
}