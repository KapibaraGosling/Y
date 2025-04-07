#include "Functions.h"
#include "Polygon.h"
#include "Point.h"
enum CreatingPolygon
{
	ByPoint = 1,
	ByCoordinates
};
int main()
{
	cout << "Enter the number of vertices ";
    int number = inputInt();
	if(number <=0) throw std::invalid_argument("Numbers of vertex must be more then zero");
    Polygon P;
	cout << "\nEnter the command number\n" << \
		CreatingPolygon::ByPoint << " - Creating a polygon based on points\n" << \
		CreatingPolygon::ByCoordinates << " - Creating a polygon using vertex coordinates\n";
	Point* points = nullptr;
	int* x = nullptr, *y = nullptr;
	int choice = inputInt();
	switch (choice)
	{
	case CreatingPolygon::ByPoint:
		points = new Point[number];
		for (size_t i = 0; i < number; i++) {
			cin >> points[i];
		}
		P = Polygon(points, number);
		
		break;

	case CreatingPolygon::ByCoordinates:
		x = new int[number];
		for (size_t i = 0; i < number; i++) { 
			cin >> x[i];
		}
		y = new int[number];
		for (size_t i = 0; i < number; i++) {
			cin >> y[i];
		}
		P = Polygon(x,y, number);

		
		break;
	default:
		throw std::invalid_argument("Entered wrong command");
		break;
	}
	delete[] points;
	delete[]x;
	delete[]y;
	P.ToString();
}
