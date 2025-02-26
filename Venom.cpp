#include "Toilet_Ananasnasdas.h"



double getCoordinate()
{
    double coordinate = 0.0;
    cin >> coordinate;
    if (cin.fail())
    {
        throw std::invalid_argument("¬ведено некорректное значение");
    }
    return coordinate;
}


double calculateRadiusOfInscribed(const Triangle& triangle) {
    return triangle.Surface() / triangle.Perimeter() * 2;
}


double calculateRadiusOfCircumscribed(const Triangle& triangle) {
    return (triangle.getSide1() * triangle.getSide2() * triangle.getSide2() / triangle.Surface() / 4);
}