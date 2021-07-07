#include "Rectangle.hpp"
#include <iostream>

int main(){
	// initialize local Rectangle variable
	Rectangle MyRectangle(100, 20, 50, 80);

	int Area = MyRectangle.GetArea();

	std::cout << "Area: " << Area << "\n";
	std::cout << "Upper Left X Cooridinate: ";
	std::cout << MyRectangle.GetUpperLeft().GetX() << "\n";
	return 0;
}
