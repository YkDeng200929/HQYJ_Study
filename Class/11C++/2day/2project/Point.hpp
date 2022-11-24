#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

class Point
{
    public:
        Point(int x, int y);
        Point(const Point& other);
        void setX(int _x);
        int getX();
        void setY(int _y);
        int getY();
        void show();

    private:
        int x;
        int y;
};

#endif