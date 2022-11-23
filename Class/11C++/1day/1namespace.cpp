#include <iostream>

using namespace std;

namespace YKDENG
{
    char name[] = "ykdeng";
    void print(void)
    {
        cout << "hello world" << endl;
    }
    namespace YKDENG2
    {
        char name[] = "ykdeng2";
    }
}

using namespace YKDENG; //全局引用
//using YKDENG::print;// 局部引用

// 匿名命名空间
namespace 
{
    int x = 33;
}

namespace yk = YKDENG;

int main(void)
{
    char name[] = "name";
    cout << name << endl;
    cout << x << endl;
    cout << yk::YKDENG2::name << endl;

    return 0;
}