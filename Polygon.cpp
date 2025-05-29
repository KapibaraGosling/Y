#include "Polygon.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>


unsigned int Polygon::screenWidth = 0;
unsigned int Polygon::screenHeight = 0;


Polygon::Polygon(unsigned int width, unsigned int height)
    : points({}) {
    screenWidth = width;
    screenHeight = height;
}
Polygon::Polygon(const Polygon& other)
    : points(other.points) {}

Polygon::Polygon(Polygon&& other) noexcept
    : points(std::move(other.points)) {}

Polygon& Polygon::operator=(const Polygon& other) {
    if (this != &other) {                
        points = other.points;
    }
    return *this;                        
}

Polygon& Polygon::operator=(Polygon&& other) noexcept {
    if (this != &other) {
        points = std::move(other.points);
    }
    return *this;
}


Polygon::Polygon(std::initializer_list<Point> points_list,
    unsigned int screen_width,
    unsigned int screen_height)
    : points(points_list) {
    screenWidth = screen_width;
    screenHeight = screen_height;
    validatePointsCheck();
}
	
Polygon::Polygon(const std::initializer_list<std::pair<int, int>>& coords,
    unsigned int screen_width, unsigned int screen_height) {
    screenWidth = screen_width;
    screenHeight = screen_height;

    points.reserve(coords.size());
    for (const auto& coord : coords) {
        points.emplace_back(coord.first, coord.second);
    }
    validatePointsCheck();
}


Point Polygon::getPoint(int sequence_number) const {
    if (sequence_number < 0 || static_cast<size_t>(sequence_number) >= points.size()) {
        throw std::out_of_range("Invalid point index");
    }
    return points[sequence_number];
}

unsigned int Polygon::getScreenWidth() const { return screenWidth; }

unsigned int Polygon::getScreenHeight() const { return screenHeight; }

void Polygon::validatePointsCheck() const {

    if (points.size() < 3) {
        throw std::invalid_argument("Polygon must have at least 3 vertices");
    }
    
    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i] == points[i - 1]) {
            throw std::logic_error("The points match");
        }
    }
    
    for (size_t i = 2; i < points.size(); ++i) {
        if (points[i].isCollinearWith( points[i - 1], points[i - 2])) {
            throw std::logic_error("Three points lie on the same straight line");
        }
    }
    
    for (const auto& point : points) {
        if (point.getX() > screenWidth || point.getY() > screenHeight) {
            throw std::invalid_argument("Vertex coordinates exceed screen bounds");
        }
    }
    
}

std::string Polygon::toString() const {
    std::ostringstream oss;
    oss << "Polygon[";
    for (size_t i = 0; i < points.size(); ++i) {
        if (i != 0) oss << ", ";
        oss << points[i];
    }
    oss << "]";
    return oss.str();
}


void Polygon::readFromStream(std::istream& is) {
    points.clear();
    Point p;
    while (is >> p) {
        points.push_back(p);
    }
    validatePointsCheck();
}
