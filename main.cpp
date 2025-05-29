#include "../GeometryLibrary/Polygon.h"
#include "../GeometryLibrary/Point.h"
#include "../GeometryLibrary/Shape.h"
#include <vector>
#include <iostream>
#include <limits>
using namespace std;
/**
 * @brief Ввод положительного целого числа с проверкой корректности
 * @return Положительное целое число
 * @throw invalid_argument Если введено не число или отрицательное значение
 */
int  inputPositiveInt(void);
enum CreatingPolygon
{
	ByPoint = 1,
	ByCoordinates
};

int main()
{
	try {
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
		P = Polygon(initializer_list<Point>(points.data(), points.data() + points.size()), screenWidth, screenHeight);
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
		P = Polygon(initializer_list<pair<int, int>>(coords.data(), coords.data() + coords.size()), screenWidth, screenHeight);
		break;
	}
	default:
		throw invalid_argument("Entered wrong command");
	}
	P.draw();
	}
	catch (const invalid_argument& e) {
		cerr << "\nError: " << e.what() << endl;
		return 1;
	}
	catch (const logic_error& e) {
		cerr << "\nLogic error: " << e.what() << endl;
		return 1;
	}
	catch (const out_of_range& e) {
		cerr << "\nOut of range error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "\nUnknown error occurred" << endl;
		return 1;
	}
	return 0;
}
int  inputPositiveInt(void){
	int number = 0.0;
	cin >> number;
	if (cin.fail() || number < 0)
	{
		throw invalid_argument("Incorrect value entered");
	}
	return number;

}