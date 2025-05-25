#pragma once

#include "Point.h"
#include "Shape.h"
#include <vector>
class Polygon : public Shape

{

private:
	
	std::vector<Point> points;
	void validatePointsCheck() const;
	const unsigned int screenWidth;
	const unsigned int screenHeight;
public:
	Polygon(unsigned int width = 1920, unsigned int height = 1080); //по умолчачнию

	Polygon(std::initializer_list<Point> points,
		unsigned int screen_width,
		unsigned int screen_height);

	Polygon(const std::initializer_list<std::pair<int, int>>& coords,
		unsigned int width, unsigned int height);

	Point getPoint(const int sequence_number) const;
	unsigned int getScreenWidth()const;
	unsigned int getScreenHeight()const;

	Polygon(const Polygon& other);
	Polygon(Polygon&& other) noexcept;


	Polygon& operator=(const Polygon& other);
	Polygon& operator=(Polygon&& other) noexcept;
	~Polygon()=default;

	void draw() const override;
	std::string toString() const override;
	void readFromStream(std::istream& is) override;
	void writeToStream(std::ostream& os) const override;
};