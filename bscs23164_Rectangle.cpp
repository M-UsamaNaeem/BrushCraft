#include "bscs23164_Rectangle.h"

int RectangleClass::counter = 0;

RectangleClass::RectangleClass(cv::Point sp, cv::Point ep, int thickness, cv::Scalar clr) : Shapes(thickness, clr), starting(sp), ending(ep) { counter++; }

RectangleClass::~RectangleClass() {
    counter--;
}

cv::Point RectangleClass::getStart() {
    return starting;
}

void RectangleClass::setStart(cv::Point s) {
    starting = s;
}

cv::Point RectangleClass::getEnd() {
    return ending;
}

void RectangleClass::setEnd(cv::Point e) {
    ending = e;
}
void RectangleClass::draw(cv::Mat canvas) {
    cv::rectangle(canvas, getStart(), getEnd(), getColour(), getThickness());
}
int RectangleClass::getCount() {
    return counter;
}