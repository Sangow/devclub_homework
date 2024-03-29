#include <iostream>
#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::~Point() {}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

double Point::distance(const Point& other) const {
    return hypot(this->x - other.x, this->y - other.y);
}

bool Point::operator==(const Point& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    return out <<"(" << point.getX() << ", " << point.getY() << ")";
}