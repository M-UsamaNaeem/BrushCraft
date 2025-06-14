#include "bscs23164_FreeLine.h"
int FreeLineClass::counter = 0;

FreeLineClass::FreeLineClass(cv::Point sp, int thickness, cv::Scalar clr) : Shapes(thickness, clr), starting(sp) {
    points.push_back(starting);
    counter++;
}
FreeLineClass::~FreeLineClass() {
    counter--;
}

cv::Point FreeLineClass::getStart() {
    return starting;
}
std::vector<cv::Point> FreeLineClass::getPoints() {
    return points;
}
cv::Point FreeLineClass::getPoint(int i) {
    return points[i];
}

void FreeLineClass::setEnd(cv::Point e) {
    points.push_back(e);
}
void FreeLineClass::draw(cv::Mat canvas) {
    for (int i = 0; i + 1 < getPoints().size(); i++) {
        cv::line(canvas, getPoint(i), getPoint(i + 1), getColour(), getThickness());
    }
}
int FreeLineClass::getCount() {
    return counter;
}