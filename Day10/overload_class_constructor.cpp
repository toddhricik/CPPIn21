// Listing 10.3 - Overloading a class constructor

#include <iostream>

class Rectangle{
	public:
		Rectangle();
		Rectangle(int width, int length);
		~Rectangle() {}
		int GetWidth() const { return itsWidth; }
		int GetLength() const { return itsLength; }
	private:
		int itsWidth;
		int itsLength;
};

Rectangle::Rectangle(){
	itsWidth = 5;
	itsLength = 10;
}

Rectangle::Rectangle(int width, int length){
	itsWidth = width;
	itsLength = length;
}

int main(){
	std::cout << "Declaring and instantiating Rect1 using default constructor Rectangle Rect1 ...\n";
	Rectangle Rect1;
	std::cout << "Using Rect1.GetWidth() we see that Rect1 has width " << Rect1.GetWidth() << std::endl;
	std::cout << "Using Rect1.GetLength() we see that Rect1 has length " << Rect1.GetLength() << std::endl;

	int aWidth, aLength;
	std::cout << "Enter a width...\n";
	std::cin >> aWidth;
	std::cout << "Enter a length...\n";
	std::cin >> aLength;

	std::cout << "\n\nDeclaring and instantiating Rect2 using overloaded constructor Rectangle Rect2(aWidth, aLength)...\n";
	Rectangle Rect2(aWidth, aLength);
	std::cout << "Using Rect2.GetWidth() we see that Rect2 has width " << Rect2.GetWidth() << std::endl;
	std::cout << "Using Rect2.GetLength() we see that Rect2 has length " << Rect2.GetLength() << std::endl;

	return 0;
}
