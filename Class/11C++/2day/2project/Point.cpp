#include "Point.hpp"

Point::Point(int _x, int _y) : x(_x), y(_y)
{
    setX(_x);
    setY(_y);
}

Point::Point(const Point& other) : x(other.x), y(other.y)// 拷贝构造函数
{
    cout << "调用拷贝构造函数" << endl;
}

void Point::setX(int _x)
{
    x = _x;
}

int Point::getX()
{
    return x;
}

void Point::setY(int _y)
{
    y = _y;
}

int Point::getY()
{
    return y;
}

void Point::show()
{
    cout << "(" << x << "," << y << ")" << endl;
}
