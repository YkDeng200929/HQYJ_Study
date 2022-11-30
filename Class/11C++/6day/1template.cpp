#include <iostream>

using namespace std;

template <typename D>
void Swap(D& data1, D& data2)
{
	D tmp = data1;
	data1 = data2;
	data2 = tmp;
}

int main(void)
{
    int a = 10, b = 20;
    cout << a << " " << b << endl;
    Swap<int>(a, b);
    cout << a << " " << b << endl;
	string str1 = "hello";
	string str2 = "world";
	cout << "------------------" << endl;
	cout << str1 << " " << str2 << endl;
	Swap<string>(str1, str2);
	cout << str1 << " " << str2 << endl;

    return 0;
}
