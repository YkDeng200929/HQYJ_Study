#include <iostream>

using namespace std;

class A
{
    public:
        A() : i(new int(10))
        {
            cout << "A 构造" << endl;
        }

        // ~A() 不加 virtual 肯能不会调用B类的析构函数
        virtual ~A()
        {
            cout << "A 析构" << endl;
            delete i;
        }
    private:
        int *i;

};

class B : public A
{
    public:
        B() : j(new int(10))
        {
            cout << "B 构造" << endl;
        }

        ~B()
        {
            cout << "B 析构" << endl;
            delete j;
        }
    private:
        int *j;


};

int main(void)
{
    A *a = new B;
    delete a;

    return 0;
}