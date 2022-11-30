#include <iostream>

using namespace std;

int main(void)
{
    int a = 30;
    float b = 3.33;
    double c = 3.14;
    cout << "a = " << a << "b = " << b << "c = " << c << endl;
    //cout << oct << showbase;
    cout << "a = " << a << "b = " << b << "c = " << c << endl;
    cout.width(10);//设置域宽, 只对第一次输出有效
    cout << right;
    cout << "a = " << a << "b = " << b << "c = " << c << endl;
    cin >> a >> b;
    cout << "a = " << a << "b = " << b << "c = " << c << endl;
    string name;

    cin >> name;
    cout << name << endl;



    return 0;
}