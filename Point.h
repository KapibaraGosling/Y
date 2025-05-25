#pragma once
#include <iostream>

class Point
{
private:
	unsigned int x;
	unsigned int y;
	
public:
	Point(unsigned int x = 0, unsigned int y = 0);
	unsigned int getX() const;
	unsigned int getY() const;
	Point& operator=(const Point& other);
	friend std::istream& operator>>(std::istream &cinP, Point& point);
	friend std::ostream& operator<<(std::ostream &coutP, const Point& point);
	Point operator+(int value) const;
	Point operator-(int value) const;
	bool isCollinearWith(const Point& p2, const Point& p3) const;
};

bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);
