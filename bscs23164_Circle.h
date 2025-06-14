#ifndef Circle_H
#define Circle_H
#include <opencv2/opencv.hpp>
#include"bscs23164_Shapes.h"


class CircleClass : public Shapes {
private:
    cv::Point center;
    double radius;
    static int counter;

public:
    CircleClass(cv::Point c, double r, int thickness, cv::Scalar clr);
    cv::Point getCenter();
    void setCenter(cv::Point c);
    double getRadius();
    void setEnd(cv::Point end)override;
    void draw(cv::Mat canvas) override;
    int getCount() override;

    ~CircleClass() override;

};
#endif

