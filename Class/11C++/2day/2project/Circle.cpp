#include "Circle.hpp"

// Circle类中有个Point对象叫o, 通过初始化列表的方式初始化o对象
Circle::Circle(int _x, int _y, int _r) : o(_x, _y)// 初始化列表
{
    cout << "创建一个圆" << endl;
    setR(_r);
}

Circle::Circle(const Circle& other) : o(other.o), r(other.r)
{
    cout << "调用圆拷贝构造函数" << endl;
}

Circle::~Circle()// 释放圆
{
    cout << "调用圆析构函数" << endl;
}

Circle::Circle(int _r) : o(0, 0)
{
    cout << "创建一个只知道半径的圆" << endl;
    setR(_r);
}

void Circle::setX(int _x)
{
    o.setX(_x);
}

int Circle::getX()
{
    return o.getX();
}

void Circle::setY(int _y)
{
    o.setY(_y);
}

int Circle::getY()
{
    return o.getY();
}

bool Circle::setR(int _r)
{
    if (r > 0)
    {
        r = _r;
        return true;
    }
    r = 0;
    return false;
}

int Circle::getR()
{
    return r;
}

void Circle::show()
{
    cout << "x = " << o.getX() << endl;
    cout << "y = " << o.getY() << endl;
    cout << "r = " << r << endl;
}

void Circle::circleAndPoint(Point p)
{
    int x2 = (p.getX() - o.getX() * (p.getX() - o.getX()));
    int y2 = (p.getY() - o.getY() * (p.getY() - o.getY()));
    int r2 = r * r;

    if (x2 + y2 == r2)
    {
        cout << "点在圆上" << endl;
    }
    else if (x2 + y2 > r2)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}