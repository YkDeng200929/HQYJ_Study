#include "Circle.hpp"

int main(void)
{
    Circle c(0, 0, 5);

    Point p(8, 9);
    Point p2(p);

    p.show();

    c.circleAndPoint(p);

    return 0;
}