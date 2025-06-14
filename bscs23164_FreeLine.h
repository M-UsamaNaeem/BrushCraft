#ifndef Free_H
#define Free_H
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include"bscs23164_Shapes.h"

class FreeLineClass :public Shapes {
private:
    cv::Point starting;
    std::vector<cv::Point> points;
    static int counter;



public:
    FreeLineClass(cv::Point sp, int thickness, cv::Scalar clr);

    cv::Point getStart();
    cv::Point getPoint(int i);

    std::vector<cv::Point> getPoints();
    void setEnd(cv::Point e)override;
    void draw(cv::Mat canvas) override;
    int getCount() override;

    ~FreeLineClass() override;


};
#endif
