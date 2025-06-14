#include"bscs23164_Paint.h"
#include "bscs23164_Line.h"
#include "bscs23164_Rectangle.h"
#include "bscs23164_Circle.h"
#include "bscs23164_Arrow.h"
#include "bscs23164_FreeLine.h"
#include "bscs23164_Shapes.h"

Paint::Paint(int h, int w) : height(h), width(w) {
	currentShape = ShapeType::RECTANGLE;
	drawing = false;
	sx = 0;
	canvas = cv::Mat(height, width, CV_8UC3, cv::Scalar(150, 150, 150));
	cv::namedWindow("My Shapes", cv::WINDOW_NORMAL);

	cv::setMouseCallback("My Shapes", Paint::handleMouseEventWrapper, this);
}
Paint::~Paint() {
	for (auto shape : shapes) {
		delete shape;
	}
	shapes.clear();
}

void Paint::cleanup() {
	for (auto shape : shapes) {
		delete shape;
	}
	shapes.clear();
	canvas = cv::Scalar(255, 255, 255);
}
int Paint::getWidth() const {
	return width;
}
cv::Scalar  Paint::getColour() const {
	return colour;
}

int  Paint::getThickness() const {
	return thickness;
}

void  Paint::setColour(cv::Scalar clr) {
	colour = clr;
}

void Paint::setThickness(int t) {
	if (t > 0) {
		thickness = t;
	}
}
void Paint::setWidth(int w) {
	width = w;
}
int Paint::getHeight() const {
	return height;
}

void Paint::setHeight(int h) {
	height = h;
}
void Paint::setCurrentShape(ShapeType::Shape currentS) { currentShape = currentS; }
ShapeType::Shape Paint::getCurrentShape() const { return currentShape; }

std::vector<Shapes*> Paint::getShape() const {
	return shapes;
}
void Paint::addShape(Shapes* shape) {
	shapes.push_back(shape);
}
void Paint::handleMouseEventWrapper(int event, int x, int y, int flags, void* param)
{
	Paint* app = static_cast<Paint*>(param);
	app->handleMouseEvents(event, x, y, flags);
}
void Paint::handleMouseEvents(int event, int x, int y, int flags) {

	if (event == cv::EVENT_LBUTTONDOWN) {
		drawing = true;
		if (getCurrentShape() == ShapeType::Line) {
			addShape(new LineClass(cv::Point(x, y), cv::Point(x, y), thickness, colour));
		}
		else if (getCurrentShape() == ShapeType::RECTANGLE) {
			addShape(new RectangleClass(cv::Point(x, y), cv::Point(x, y), thickness, colour));
		}
		else if (getCurrentShape() == ShapeType::CIRCLE) {
			addShape(new CircleClass(cv::Point(x, y), 0, thickness, colour));
		}
		else if (getCurrentShape() == ShapeType::ARROW) {
			addShape(new ArrowClass(cv::Point(x, y), cv::Point(x, y), thickness, colour));
		}
		else {
			addShape(new FreeLineClass(cv::Point(x, y), thickness, colour));
		}
		return;
	}
	if (event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_FLAG_LBUTTON)) {
		shapes.back()->setEnd(cv::Point(x, y));
		return;
	}

	if (event == cv::EVENT_LBUTTONUP && !(flags & cv::EVENT_FLAG_SHIFTKEY)) {
		shapes.back()->draw(canvas);
		drawing = false;
		return;
	}
}
void Paint::saveCanvas(const std::string& filename) {
	if (filename.substr(filename.find_last_of('.')) != ".png") {
		throw std::invalid_argument("Filename should finish with .png");
	}
	cv::imwrite(filename, canvas);
}
void Paint::run() {
	while (true) {
		if (drawing) {
			cv::Mat tCanvas = canvas.clone();
			for (int i = 0; i < shapes.size(); i++) {
				shapes.at(i)->draw(tCanvas);
			}
			cv::imshow("My Shapes", tCanvas);
		}
		else {
			cv::imshow("My Shapes", canvas);
		}
		char key = cv::waitKey(1);

		if (key == 'R') {
			if (colour[2] < 255) {
				colour[2] += 10;
			}
		}
		else if (key == 'G') {
			if (colour[1] < 255) {
				colour[1] += 10;
			}
		}
		else if (key == 'B') {
			if (colour[0] < 255) {
				colour[0] += 10;
			}
		}
		else if (key == 'r') {
			if (colour[2] > 0) {
				colour[2] -= 10;
			}
		}
		else if (key == 'g') {
			if (colour[1] > 0) {
				colour[1] -= 10;
			}
		}
		else if (key == 'b') {
			if (colour[0] > 0) {
				colour[0] -= 10;
			}
		}
		if (key == '+') {
			if (thickness < 10) {
				thickness++;
			}
		}
		else if (key == '-') {
			if (thickness > 1) {
				thickness--;
			}
		}
		if (key == '5') {
			setCurrentShape(ShapeType::FREE);
		}
		else if (key == '4') {
			setCurrentShape(ShapeType::ARROW);
		}
		else if (key == '3') {
			setCurrentShape(ShapeType::CIRCLE);
		}
		else if (key == '2') {
			setCurrentShape(ShapeType::RECTANGLE);
		}
		else if (key == '1') {
			setCurrentShape(ShapeType::Line);
		}
		else if (key == 's' || key == 'S') {
			try {
				saveCanvas("My Shapes.png");
			}
			catch (const std::invalid_argument& exc) {
				std::cout << "Exception: " << exc.what() << std::endl;
				std::cout << "App terminating..." << std::endl;
			}
			for (int i = 0; i < shapes.size(); i++) {
				delete shapes.at(i);
			}
			shapes.clear();
			break;
		}
		else if (key == 'c' || key == 'C') {
			for (auto shape : shapes) {
				delete shape;
			}
			shapes.clear();
			canvas = cv::Scalar(255, 255, 255);
		}
		else if (key == 27) {
			cleanup();
			break;
		}
	}
	cv::destroyAllWindows();
}