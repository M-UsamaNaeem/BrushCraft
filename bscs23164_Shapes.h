#ifndef SHAPES
#define SHAPES
#include<opencv2/opencv.hpp>

#include<iostream>
#include<vector>



class Shapes {
private:

	int thickness;
	cv::Scalar colour;


public:

	Shapes(int t, cv::Scalar clr);
	int getThickness()const;

	cv::Scalar getColour()const;

	void setThickness(int t);

	void setColour(cv::Scalar clr);

	virtual void draw(cv::Mat canvas) = 0;
	virtual void setEnd(cv::Point) = 0;
	virtual int getCount() = 0;
	virtual ~Shapes() {}
};
#endif
