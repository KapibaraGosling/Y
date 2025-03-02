#pragma once

#include "Point.h"

class Polygon

{

private:

	int number;
	const Point* point;

public:
	Polygon();

	Polygon(const Point* points, const int number);

	Polygon(const int* x, const int* y, const int number);

	Point getPoint(const int sequence_number) const;

	~Polygon();

	void ToString();
};