#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

class Point
{
    public:
        Point(int x, int y);
        Point(const Point& other);
        ~Point(); // 释放点
        void setX(int _x);
        int getX();
        void setY(int _y);
        int getY();
        void show();
        Point& operator++(); // 前置++
        Point operator++(int); // 后置++ 因为无法重载, 所以带占位参数

        friend ostream& operator<<(ostream& out, const Point& p);

    private:
        int x;
        int y;
};

#endif