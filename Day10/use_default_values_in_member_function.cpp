// Listing 10.2 Default values in member functions
#include <iostream>

class Rectangle{
	public:
		Rectangle(int width, int height);
		~Rectangle(){}
		void DrawShape(int aWidth, int aHeight, bool UseCrurrentVals = false) const;
	private:
		int itsWidth;
		int itsHeight;
};

Rectangle::Rectangle(int width, int height):
itsWidth(width),
itsHeight(height)
{}

// default values used for third parameter
void Rectangle::DrawShape(int width, int height, bool UseCurrentVals) const{
	int printWidth;
	int printHeight;

	if(UseCurrentVals==true){				// use current class values of itsWidth and itsHeight
		printWidth = itsWidth;
		printHeight = itsHeight;
	}
	else{									// use vaules passed in as parameters in calling function
		printWidth = width;
		printHeight = height;
	}
	for(int i=0; i<printHeight; i++){
		for(int j=0; j<printWidth; j++){
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int main(){
	std::cout << "Declaring and initializing a rectangle theRect(30,5)...\n";
	Rectangle theRect(30, 5);
	std::cout << "Using theRect.DrawShape(0, 0, true) to draw rectangle using class members itsHeight=30 and itsWidth=5....\n";
	theRect.DrawShape(0, 0, true);
	std::cout << "Using theRect.DrawShape(40, 2) which implies UseCurrentVals is set to the default of \"false\"...\n";
	theRect.DrawShape(40, 2);
	return 0;
}
