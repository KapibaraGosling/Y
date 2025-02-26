#include "₍^. .^₎.h"
#include "Ryangosling.h"
#include "Toilet_Ananasnasdas.h"

int main()
{
    Point p1(getCoordinate(), getCoordinate()), p2(getCoordinate(), getCoordinate()), p3(getCoordinate(), getCoordinate());
    Triangle t(p1, p2, p3);
    cout << "Radius of a сircle inscribed in a triangle:\t" << calculateRadiusOfInscribed(t) <<
        "\nRadius of a circle circumscribed around a triangle\t" << calculateRadiusOfCircumscribed(t);
    return 0;
}
