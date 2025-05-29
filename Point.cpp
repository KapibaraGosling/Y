#include "Point.h"
#include <limits>
bool operator==(const Point& point1, const Point& point2)
{
    return point1.getX() == point2.getX() && point1.getY() == point2.getY();
}

bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Point::isCollinearWith(const Point& p2, const Point& p3) const {
    int area = (this->x) * (p2.y - p3.y) +
        (p2.x) * (p3.y - this->y) +
        (p3.x) * (this->y - p2.y);

    return area ==0;
}

std::istream& operator>>(std::istream& is, Point& point) {
    int tempX, tempY;  // Временные переменные для проверки отрицательных значений
    is >> tempX >> tempY;

    if (is.fail() || tempX < 0 || tempY < 0) {\
        throw std::invalid_argument("Coordinates must be unsigned integers");
    }

    point.x = static_cast<unsigned int>(tempX);
    point.y = static_cast<unsigned int>(tempY);
    return is;
}


std::ostream& operator<<(std::ostream &outP, const Point& point) {
    outP << "(" << point.x << "; " << point.y << ")\n";
    return outP;
}


Point::Point(unsigned int x, unsigned int y) : x(x), y(y) {}

unsigned int Point::getX() const {
    return x;
}

unsigned int Point::getY() const {
    return y;
}

Point Point::operator+(int value) const {
    return Point(x + value, y + value);
}

Point Point::operator-(int value) const {
    if (value > x || value > y) {
        throw std::out_of_range("Subtraction would result in negative coordinates");
    }
    return Point(x - value, y - value);
}