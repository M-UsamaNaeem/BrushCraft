#include "bscs23164_Line.h"

int LineClass::counter = 0;

LineClass::LineClass(cv::Point sp, cv::Point ep, int thickness, cv::Scalar clr) : Shapes(thickness, clr), starting(sp), ending(ep) {
    counter++;
}

LineClass::~LineClass() {
    counter--;
}

cv::Point LineClass::getStart() {
    return starting;
}

void LineClass::setStart(cv::Point s) {
    starting = s;
}

cv::Point LineClass::getEnd() {
    return ending;
}

void LineClass::setEnd(cv::Point e) {
    ending = e;
}

void LineClass::draw(cv::Mat canvas) {
    cv::line(canvas, getStart(), getEnd(), getColour(), getThickness());
}
int LineClass::getCount() {
    return counter;
}


