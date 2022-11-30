#include "Circle.hpp"

ostream& operator<<(ostream& out, const Point& p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
int main(void)
{
    Circle c(0, 0, 5);

    Point p(8, 9);
    //Point p2(p);
    p++;

    //p.show();
    cout << p << endl;
    Circle d(c);
    //c.circleAndPoint(p);

    return 0;
}