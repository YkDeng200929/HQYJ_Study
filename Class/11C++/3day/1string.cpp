#include <iostream>

using namespace std;

int main(void)
{
    
    string a = "hello";
    string b = "world";
    string c = a + b;
    cout << c << endl;
    cout << c.length() << endl;
    c.clear();
    cout << c << endl;

    return 0;
}