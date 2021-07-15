// Listing 10.1 Overlaoding class member functions
#include <iostream>

class Rectangle{
	public:
		Rectangle(int width, int height);
		~Rectangle(){}
	
		//ovlerload class function DrawShape
		void DrawShape() const;
		void DrawShape(int aWidth, int aHeight) const;

	private:
		int itsWidth;
		int itsHeight;
};

Rectangle::Rectangle(int width, int height){
	itsWidth = width;
	itsHeight = height;
}

void Rectangle::DrawShape() const{
	DrawShape(itsWidth, itsHeight);
}

void Rectangle::DrawShape(int width, int height) const {
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int main(){
	std::cout << "Declaring and instantiating theRect(30,5)...\n";
	Rectangle theRect(30,5);
	std::cout << "Calling theRect.DrawShape()... \n";
	theRect.DrawShape();
	std::cout << "Calling theRectDrawShape(40, 2)...\n";
	theRect.DrawShape(40, 2);
	return 0;
}

