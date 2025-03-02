#include "Point.h"
bool operator==(const Point& point1, const Point& point2)
{
    return point1.getX() == point2.getX() && point1.getY() == point2.getY();
}

bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}


Point Point::operator+(const Point& other) const {
    return Point(this->x + other.x, this->y + other.y);
}
Point Point::operator-(const Point& other) const {
    return Point(this->x - other.x, this->y - other.y);
}

std::istream& operator>>(std::istream &cinP, Point& point) {
    cinP >> point.x >> point.y;
    if (cinP.fail())
    {
        throw std::invalid_argument("Incorrect value entered");
    }
    return cinP;
}

std::ostream& operator<<(std::ostream &coutP, Point& point) {
    coutP << "(" << point.x << "; " << point.y << ")\n";
    return coutP;
}


Point::Point(const int x, const int y) :
    x{ x }, y{ y }{}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}