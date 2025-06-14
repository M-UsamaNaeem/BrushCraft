#include"bscs23164_Circle.h"
int CircleClass::counter = 0;
CircleClass::CircleClass(cv::Point c, double r, int thickness, cv::Scalar clr) : Shapes(thickness, clr), center(c), radius(r) { counter++; }
CircleClass::~CircleClass() {
    counter--;
}
cv::Point CircleClass::getCenter() {
    return center;
}
void CircleClass::setCenter(cv::Point c) {
    center = c;
}
double CircleClass::getRadius() {
    return radius;
}
void CircleClass::setEnd(cv::Point end) {
    radius = abs(center.x - end.x);
}

void CircleClass::draw(cv::Mat canvas) {
    cv::circle(canvas, getCenter(), getRadius(), getColour(), getThickness());
}

int CircleClass::getCount() {
    return counter;
}