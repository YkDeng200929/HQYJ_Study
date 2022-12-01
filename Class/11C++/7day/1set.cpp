#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    set<int> array;
    array.insert(10);
    array.insert(30);
    array.insert(50);
    array.insert(20);
    array.insert(11);

    set<int>::iterator it = array.find(20);
    if (it == array.end())
    {
        cout << "No value" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    set<int>::iterator itLow = array.lower_bound(33);
    cout << *itLow << endl;

    set<int>::iterator itUpper = array.lower_bound(33);
    cout << *itUpper << endl;

    return 0;
}