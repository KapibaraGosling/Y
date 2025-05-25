#pragma once
#include <iostream>
#include <vector>
#include "Point.h"

class Shape {
public:
    virtual void draw() const = 0;
    virtual std::string toString() const = 0;

    virtual ~Shape() = default;

    virtual void readFromStream(std::istream& is) = 0;
    virtual void writeToStream(std::ostream& os) const = 0;

    friend std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.readFromStream(is);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.writeToStream(os);
        return os;
    }
};