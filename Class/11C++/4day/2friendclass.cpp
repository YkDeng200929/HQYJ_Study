#include <iostream>

using namespace std;

class Wife_house;

class My_house
{
    public:
    My_house(int key) : key(key) {;}

    void vist(const Wife_house& my_woman);

    friend Wife_house;

    private:
    int key;

};

class Wife_house
{
    public:
    Wife_house(int key) : key(key) {;}

    friend My_house;

    void vist(const My_house& my_man)
    {
        cout << "key: " << my_man.key << " visit my man house" << endl;
    }

    private:
    int key;
};

void My_house::vist(const Wife_house& my_woman)
{
    cout << "key: " << my_woman.key << " visit my woman house" << endl;
}

int main(void)
{
    My_house ykdeng(34);
    Wife_house my_woman(66);

    my_woman.vist(ykdeng);
    ykdeng.vist(my_woman);

    return 0;
}