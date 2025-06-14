#pragma once

#include"bscs23164_Shapes.h"
#include<iostream>
#include<vector>

namespace ShapeType {
    enum Shape {
        Line, CIRCLE, RECTANGLE, ARROW, FREE
    };
}

class Paint {
private:
    std::vector<Shapes*> shapes;
    cv::Scalar colour = cv::Scalar(0, 0, 0);
    int thickness = 2;
    void handleMouseEvents(int event, int x, int y, int flags);
    int sx; bool drawing;
    cv::Mat canvas;
    int height, width;
    ShapeType::Shape currentShape;

public:
    Paint(int h, int w);
    ~Paint();
    std::vector<Shapes*> getShape() const;
    int getHeight()const;
    int getWidth()const;
    cv::Scalar getColour() const;
    int getThickness() const;
    void setHeight(int h);
    void setWidth(int w);
    void setColour(cv::Scalar clr);
    void setThickness(int t);
    void addShape(Shapes* shape);
    ShapeType::Shape getCurrentShape()const;
    void setCurrentShape(ShapeType::Shape currentS);
    void run();
    static void handleMouseEventWrapper(int event, int x, int y, int flags, void* param);
    void saveCanvas(const std::string& filename);
    void cleanup();
};
