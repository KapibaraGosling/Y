#pragma once

#include "₍^. .^₎.h"

class Triangle
{
private:
    Point point1, point2, point3;
    double side1, side2, side3;
public:
    Triangle(const Point& point1, const Point& point2, const Point& point3);
        double getSide1() const;
        double getSide2() const;
        double getSide3() const;
        double Perimeter() const;
        double Surface() const;
};