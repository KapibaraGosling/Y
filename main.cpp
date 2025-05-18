#include "Polygon.h"
#include "Point.h"
#include "Tests.h"
using namespace std;
int  inputInt(void)
{
	int number = 0.0;
	cin >> number;
	if (cin.fail())
	{
		throw invalid_argument("Incorrect value entered");
	}
	return number;

}
enum CreatingPolygon
{
	ByPoint = 1,
	ByCoordinates
};
int main()
{
	run_all_tests();
	cout << "\n\n";////////////////
	cout << "Enter the number of vertices ";
    int number = inputInt();
	if(number <=0) throw invalid_argument("Numbers of vertex must be more then zero");
	cout << "\nEnter the command number\n" << \
		CreatingPolygon::ByPoint << " - Creating a polygon based on points\n" << \
		CreatingPolygon::ByCoordinates << " - Creating a polygon using vertex coordinates\n";
	int choice=inputInt();
	Polygon P;
	switch (choice)
	{
	case CreatingPolygon::ByPoint: {
		vector<Point> points;
		points.reserve(number);
		cout << "Enter " << number << " points (x y format):\n";
		for (int i = 0; i < number; ++i) {
			Point pt;
			cin >> pt;
			points.push_back(pt);
		}
		P = Polygon(points.data(), points.size());
		break;
	}

	case CreatingPolygon::ByCoordinates: {
		vector<int> x(number), y(number);
		cout << "Enter " << number << " x-coordinates:\n";
		for (int i = 0; i < number; ++i) {
			x[i] = inputInt();
		}

		cout << "Enter " << number << " y-coordinates:\n";
		for (int i = 0; i < number; ++i) {
			y[i] = inputInt();
		}
		P = Polygon(x.data(), y.data(), number);
		break;
	}
	default:
		throw std::invalid_argument("Entered wrong command");
	}
	P.ToString();
	return 0;
}
