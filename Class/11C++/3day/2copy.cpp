#include <iostream>

using namespace std;

class num
{
    public:
    //num(int i = 0, int *j = NULL) : i(i), j(j) 或者
    num(int i = 0, int j = 0) : i(i), j(new int(j))
    {
        cout << "构造函数" << endl;
    }
    num(const num&number) : i(number.i), j(new int (*(number.j)))
    {
        cout << "深拷贝" << endl;
    }
    ~num()
    {
        if (j != NULL)
        {
            delete j;
            cout << "析构函数" << endl;
        }
    }

    int i;
    int *j;
};

int main(void)
{
    num a(10, 20);
    num b = a;

    cout << b.j << endl;
    cout << a.j << endl;
    
    return 0;
}