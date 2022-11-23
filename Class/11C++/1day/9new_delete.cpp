#include <iostream>

using namespace std;

int main(void)
{
    int *q = new int; // 申请内存不初始化
    int *p = new int(10); // 申请内存并初始化

    delete q;
    delete p;

    int *arr = new int[5]{10, 20, 30, 40, 50}; // 给数组申请空间
    // 大括号一定能初始化 -std=c++11

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    delete []arr;

    return 0;
}