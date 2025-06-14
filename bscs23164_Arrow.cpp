#include"bscs23164_Arrow.h"
int ArrowClass::counter = 0;
ArrowClass::ArrowClass(cv::Point sp, cv::Point ep, int thickness, cv::Scalar clr) : Shapes(thickness, clr), starting(sp), ending(ep) { counter++; }

ArrowClass::~ArrowClass() {
    counter--;
}
cv::Point ArrowClass::getStart() {
    return starting;
}

void ArrowClass::setStart(cv::Point s) {
    starting = s;
}

cv::Point ArrowClass::getEnd() {
    return ending;
}

void ArrowClass::setEnd(cv::Point e) {
    ending = e;
}
void ArrowClass::draw(cv::Mat canvas) {
    cv::arrowedLine(canvas, getStart(), getEnd(), getColour(), getThickness());
}
int ArrowClass::getCount() {
    return counter;
}