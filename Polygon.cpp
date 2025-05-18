// Polygon methods 



#include "Polygon.h"
#include <algorithm>
#include <stdexcept>

Polygon::Polygon() {
    points = {};
}


Polygon::Polygon(const Point* points, const size_t number) {
    if (number > 0 && points == nullptr) throw std::invalid_argument("Null pointer passed");

    this->points.assign(points, points + number);
    validatePointsCheck();
}
	
Polygon::Polygon(const int* x, const int* y, const size_t number) {
   
    if (number > 0 && (x == nullptr || y == nullptr)) {
        throw std::invalid_argument("Null pointer passed");
    }

    this->points.reserve(number);
    for (size_t i = 0; i < number; ++i) {
        points.emplace_back(x[i], y[i]);
    }

    validatePointsCheck();
}


Point Polygon::getPoint(int sequence_number) const {
    if (sequence_number < 0 || static_cast<size_t>(sequence_number) >= points.size()) {
        throw std::out_of_range("Invalid point index");
    }
    return points[sequence_number];
}
void Polygon::validatePointsCheck() const {
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

}

void Polygon::ToString() const {
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << "vertex " << i+1 << ": " << points[i] << "\n";
    }
}