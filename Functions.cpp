#include "Functions.h"

bool OnSameLine(const Point& p1, const Point& p2, const Point& p3) {
    int area =  p1.getX() * (p2.getY() - p3.getY()) +
                p2.getX() * (p3.getY() - p1.getY()) +
                p3.getX() * (p1.getY() - p2.getY());
    // ≈сли площадь равна нулю, точки лежат на одной пр€мой
    return area == 0;
}



int  inputInt(void)
{
    int number = 0.0;
    cin >> number;
    if (cin.fail())
    {
        throw std::invalid_argument("Incorrect value entered");
    }
    return number;

}

