// 友元
#include <iostream>

using namespace std;

class Human
{
    public:
    Human(int id, string name):id(id), name(name)
    {}

    friend void check(const Human& man);
    private:
    int id;
    string name;
};

void check(const Human& man)
{
    cout << man.id << ' ' << man.name << "作核酸" << endl;
}

int main(void)
{
    Human ykdeng(420821, "ykdeng");
    check(ykdeng);

    return 0;
}