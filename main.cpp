#include "Polygon.h"
#include "Point.h"
#include <vector>
#include <iostream>
using namespace std;
int  inputPositiveInt(void)
{
	int number = 0.0;
	cin >> number;
	if (cin.fail()||number<0)
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
	const unsigned int screenWidth = 1920;
	const unsigned int screenHeight = 1080;

	cout << "Enter the number of vertices ";
	int vertexNumber = inputPositiveInt();
	if (vertexNumber < 3) throw invalid_argument("Polygon must have at least 3 vertices");

	cout << "\nEnter the command number\n" << \
		CreatingPolygon::ByPoint << " - Creating a polygon based on points\n" << \
		CreatingPolygon::ByCoordinates << " - Creating a polygon using vertex coordinates\n";
	int choice= inputPositiveInt();

	Polygon P(screenWidth, screenHeight);
	switch (choice)
	{
	case CreatingPolygon::ByPoint: {


		cout << "Enter " << vertexNumber << " points:\n";
		vector<Point> points;
		points.reserve(vertexNumber);

		for (int i = 0; i < vertexNumber; ++i) {
			unsigned x = inputPositiveInt();
			unsigned y = inputPositiveInt();
			points.emplace_back(x, y);
		}
		Polygon(initializer_list<Point>(points.data(), points.data() + points.size()), screenWidth, screenHeight);
		break;
	}

	case CreatingPolygon::ByCoordinates: {
		vector<pair<int, int>> coords;
		coords.reserve(vertexNumber);
		for (size_t i = 0; i < vertexNumber; ++i) {
			int x = inputPositiveInt();
			int y = inputPositiveInt();
			coords.emplace_back(x, y);
		}
		Polygon(initializer_list<pair<int, int>>(coords.data(), coords.data() + coords.size()), screenWidth, screenHeight);
		break;
	}
	default:
		throw invalid_argument("Entered wrong command");
	}
	P.draw();
	return 0;
}
