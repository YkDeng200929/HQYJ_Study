#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"

class Circle
{
    public:
        Circle(int _x, int _y, int _r = 0);// 构造函数
        Circle(const Circle& other);
        Circle(int r);
        void setX(int _x);
        int getX();
        void setY(int _y);
        int getY();
        bool setR(int _r);
        int getR();

        void show();
        void circleAndPoint(Point p);

    private:
        Point o;   // 组合关系
        int r;
};

#endif