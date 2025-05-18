#pragma once
#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	Point(const int x = 0, const int y = 0);
	int getX() const;
	int getY() const;
	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	Point& operator=(const Point& other);
	friend std::istream& operator>>(std::istream &cinP, Point& point);
	friend std::ostream& operator<<(std::ostream &coutP, const Point& point);
	
	bool isCollinearWith(const Point& p2, const Point& p3) const;
};

bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);
