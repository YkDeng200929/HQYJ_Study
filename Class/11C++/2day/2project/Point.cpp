#include "Point.hpp"

Point::Point(int _x, int _y) : x(_x), y(_y)
{
    setX(_x);
    setY(_y);
}

Point::Point(const Point& other) : x(other.x), y(other.y)// 拷贝构造函数
{
    cout << "调用点拷贝构造函数" << endl;
}

Point::~Point() // 释放点
{
    cout << "调用点析构函数" << endl;
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

Point& Point::operator++() // 前置++
{
    ++x;
    ++y;
    return *this; // 对自己++后返回
}
Point Point::operator++(int) // 后置++ 因为无法重载, 所以带占位参数
{
    Point tmp(*this); // 先拷贝自己的内容到一个临时对象
    ++x;
    ++y;
    return tmp; // 然后返回该对象
}