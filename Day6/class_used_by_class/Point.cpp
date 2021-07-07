// point definition
#include "Point.hpp"

Point::Point(){}
Point::~Point(){}
void Point::SetX(int x){
	itsX = x;
}
void Point::SetY(int y){
	itsY = y;
}
int Point::GetX() const{
	return itsX;
}
int Point::GetY() const{
	return itsY;
}

