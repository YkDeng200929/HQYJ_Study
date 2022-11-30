#include <iostream>
#include <cmath>

using namespace std;

class Ouadrangle
{
public:
    virtual void cal_s() = 0;
    virtual void cal_c() = 0;
};

class Rhombus : public Ouadrangle
{
public:
    Rhombus(int x) : x(x){;}

    virtual void cal_s()
    {
        cout << (x/2) * sqrt(3) << endl;
    }

    virtual void cal_c()
    {
        cout << x * 4 << endl;
    }
private:
    int x;
};

class Rect : public Ouadrangle
{
public:
    Rect(int x, int y) : x(x), y(y){;}

    virtual void cal_s()
    {
        cout << x * y << endl;
    }

    virtual void cal_c()
    {
        cout << 2*(x + y) << endl;
    }
private:
    int x;
    int y;
};

int main(void)
{
    Rhombus first(4);
    cout << "Rhombus(S): ";
    first.cal_s();
    cout << "Rhombus(C): ";
    first.cal_c();
    cout << "-------------------" << endl;
    Rect second(5, 10);
    cout << "Rect(S): ";
    second.cal_s();
    cout << "Rect(C): ";
    second.cal_c();


    return 0;
}