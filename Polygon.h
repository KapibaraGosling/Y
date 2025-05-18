#pragma once

#include "Point.h"
#include <vector>
class Polygon

{

private:
	
	std::vector<Point> points;
	void validatePointsCheck() const;
public:
	Polygon();

	Polygon(const Point* points, const size_t number);

	Polygon(const int* x, const int* y, const size_t number);

	Point getPoint(const int sequence_number) const;

	

	Polygon(const Polygon& other) = default;
	Polygon(Polygon&& other) noexcept = default;
	Polygon& operator=(const Polygon& other) = default;
	Polygon& operator=(Polygon&& other) noexcept = default;
	~Polygon()=default;
	void ToString() const;
};