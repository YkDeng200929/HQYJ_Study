#include <iostream>

using namespace std;

class A
{
public:
    A() : i(2), j(3), k(4)
    {}

    void show()
    {
        cout << "public: i: " << i << endl;
        cout << "private: j: " << j << endl;
        cout << "protected: k: " << k << endl;
    }

    int i;
private:
    int j;
protected:
    int k;

};

class B : public A
{
public:
    void show()
    {
        cout << "A::public: i: " << i << endl;
        //cout << "j: " << j << endl; 
        cout << "A::protected: k: " << k << endl;
    }
};

class C : protected B
{
public:
    void show()
    {
        cout << "A::public: i: " << i << endl;
        //cout << j << endl;
        cout << "A::protected: k: " << k << endl;
    }
};

int main(void)
{
    A a;
    a.show();
    cout << "---------------------" << endl;
    B b; 
    b.show();
    cout << "---------------------" << endl;
    C c;
    c.show();
    cout << "---------------------" << endl;

    return 0;
}