#include <iostream>

using namespace std;

namespace {
    int a = 9;
    int b = 8;
}

namespace hello {
    int a = 10;
}

namespace test {
    int a = 9;
    int b = 8;
}

using test::a;

int main(void)
{
    cout << a << endl;

    return 0;
}