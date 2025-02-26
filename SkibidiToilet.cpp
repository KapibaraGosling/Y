#include "₍^. .^₎.h"
#include "RyanGosling.h"
#include "Toilet_Ananasnasdas.h"

Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3):
point1{ point1 }, point2{ point2 }, point3{ point3 },
side1{ sqrt(pow(point2.getX() - point3.getX(), 2) + pow(point2.getY() - point3.getY(), 2)) },
side2{ sqrt(pow(point3.getX() - point1.getX(), 2) + pow(point3.getY() - point1.getY(), 2)) },
side3{ sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2)) }
{
    if (point1 == point2 || point1 == point3 || point2 == point3)
    {
        throw std::logic_error("The points match");
    }
    if (!((side1 <= side2 + side3) && (side2 <= side1 + side3) && (side3 <= side1 + side2)))
    {
        throw std::logic_error("incorrect side lengths");
    }
}

double Triangle::getSide1() const
{
    return side1;
}

double Triangle::getSide2() const
{
    return side2;
}

double Triangle::getSide3() const
{
    return side3;
}

double Triangle::Perimeter() const
{
    return (side1 + side2 + side3);
}

double Triangle::Surface() const
{
    return (sqrt(Perimeter()/2*(Perimeter()/2-side1)*(Perimeter()/2-side2)*(Perimeter() / 2 - side2)));
}

