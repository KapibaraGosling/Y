// Polygon methods 

#include "Point.h"

#include "Polygon.h"

#include "Functions.h"


Polygon::Polygon() {
	number = 0;
	point = nullptr;
}

Polygon::Polygon(const Point* points, const int number) :

number{ number }, point{ points }
{
	for (size_t i = 1; i < number; i++) {
		if (point[i] == point[i-1])
			throw std::logic_error("The points match");
	}

	for (size_t i = 2; i < number; i++) {
		if (OnSameLine(points[i], points[i-1], points[i-2])) {
			throw std::logic_error("Three points lie on the same straight line");
		}
	}
}

	
Polygon::Polygon(const int* x, const int* y, const int number)
{
	Point* points = new Point[number];
	for (size_t i = 0; i < number; i++) {
		points[i] = Point(x[i], y[i]);
	}

	*this = Polygon(points, number);

	delete[] points;
}

Point Polygon::getPoint(const int sequence_number) const {
	if (sequence_number < 0 || sequence_number >= number) {
		throw std::out_of_range("Invalid sequence number");
	}
	return point[sequence_number];
}
Polygon::~Polygon() {
	delete[] point; 
}


void Polygon::ToString() {
	for (size_t i=0; i < this->number; i++) {
		cout << "vertex  " << i << ": " << &this->point[i] << std::endl;
	}
}