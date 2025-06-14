#include "bscs23164_Shapes.h"



Shapes::Shapes(int t, cv::Scalar clr) : thickness(t), colour(clr) {}
int Shapes::getThickness() const { return thickness; }
cv::Scalar Shapes::getColour()  const { return colour; }
void Shapes::setThickness(int t) { thickness = t; }
void Shapes::setColour(cv::Scalar clr) { colour = clr; }

