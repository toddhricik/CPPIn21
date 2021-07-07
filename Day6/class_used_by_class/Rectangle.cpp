// rectangle definition
#include "Rectangle.hpp"

Rectangle::Rectangle(int top, int left, int bottom, int right){
	itsTop = top;
	itsLeft = left;
	itsBottom = bottom;
	itsRight = right;

	itsUpperLeft.SetX(left);
	itsUpperLeft.SetY(top);

	itsUpperRight.SetX(right);
	itsUpperRight.SetY(top);

	itsLowerLeft.SetX(left);
	itsLowerLeft.SetY(bottom);

	itsLowerRight.SetX(right);
	itsLowerRight.SetY(bottom);
}

Rectangle::~Rectangle(){
}

int Rectangle::GetTop() const{
	return itsTop;
}

int Rectangle::GetLeft() const{
	return itsLeft;
}

int Rectangle::GetBottom() const{
	return itsBottom;
}

int Rectangle::GetRight() const{
	return itsRight;
}

Point Rectangle::GetUpperLeft() const{
	return itsUpperRight;
}

Point Rectangle::GetLowerLeft() const{
	return itsLowerLeft;
}

Point Rectangle::GetUpperRight() const{
	return itsUpperRight;
}

Point Rectangle::GetLowerRight() const{
	return itsLowerRight;
}

void Rectangle::SetUpperLeft(Point Location){
	itsUpperLeft = Location;
}

void Rectangle::SetLowerLeft(Point Location){
	itsLowerLeft = Location;
}

void Rectangle::SetUpperRight(Point Location){
	itsUpperRight = Location;
}

void Rectangle::SetLowerRight(Point Location){
	itsLowerRight = Location;
}

void Rectangle::SetTop(int top){
	itsTop = top;
}

void Rectangle::SetLeft(int left){
	itsLeft = left;
}

void Rectangle::SetBottom(int bottom){
	itsBottom = bottom;
}

void Rectangle::SetRight(int right){
	itsRight = right;
}

// compute area of the rectangle by finding sides,
// establish width and height and then multiply
int Rectangle::GetArea() const{
	int Width = itsRight - itsLeft;
	int Height = itsTop - itsBottom;
	return (Width * Height);
}

