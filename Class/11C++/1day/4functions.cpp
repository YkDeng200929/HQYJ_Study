#include <iostream>

using namespace std;

/*C++允许函数带默认参数*/
/*常规*/
void addNum(int a, int b)
{
    cout << "a + b = " << a + b << endl;
}

/*带默认值参数*/
void addNum2(int a = 3, int b = 4)
{
    cout << "a + b = " << a + b << endl;
}

int main(void)
{
    addNum(3, 4);
    addNum2();
    /*会优先替换第一个参数*/
    addNum2(3);

    return 0;
}