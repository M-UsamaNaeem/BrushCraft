//#pragma_once
#ifndef CLASS_H
#define CLASS_H

#include<opencv2/opencv.hpp>
#include<iostream>
#include"bscs23164_Shapes.h"


class LineClass :public Shapes {
private:
    cv::Point starting;
    cv::Point ending;
    static int counter;

public:
    LineClass(cv::Point sp, cv::Point ep, int thickness, cv::Scalar clr);

    cv::Point getStart();
    void setStart(cv::Point s);
    cv::Point getEnd();
    void setEnd(cv::Point e) override;
    void draw(cv::Mat canvas) override;
    int getCount() override;

    ~LineClass() override;
};
#endif
