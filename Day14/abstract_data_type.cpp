// Listing 14.8 - Demonstrates pure virtual functions as part of an abstract data type
#include <iostream>
class Shape{
	public:
		Shape() {}
		virtual ~Shape() {}
		virtual long GetArea() = 0;				// pure virtual function
		virtual long GetPerim() = 0;				// pure virtual function
		virtual void Draw() = 0;				// pure virtual function
	private:
};
class Circle : public Shape{
	public:
		Circle(int radius) : itsRadius(radius) {}
		~Circle() {}
		virtual long GetArea() { return 3 * itsRadius * itsRadius; }
		virtual long GetPerim() { return 6 * itsRadius; }
		virtual void Draw();
	private:
		int itsRadius;
		int itsCircumference;
};
void Circle::Draw(){
	std::cout << "Circle is being drawn...\n";
}
class Rectangle : public Shape{
	public:
		Rectangle(int len, int width) : itsLength(len), itsWidth(width){}
		virtual ~Rectangle() {}
		virtual long GetArea() { return itsLength * itsWidth; }
		virtual long GetPerim() { return 2 * itsLength + 2 * itsWidth; }
		virtual int GetLength() { return itsLength; }
		virtual int GetWidth() { return itsWidth; }
		virtual void Draw();
	protected:							// Book has this as private. Typo?
		int itsLength;
		int itsWidth;
};
void Rectangle::Draw(){
	for(int i=0; i<itsLength; i++){
		for(int j=0; j<itsWidth; j++)
			std::cout << "x ";
		std::cout << std::endl;
	}
}
class Square : public Rectangle{
	public:
		Square(int len);
		Square(int len, int width);
		virtual ~Square() {}
		virtual long GetPerim() { return 4 * itsLength; }
};
Square::Square(int len) : Rectangle(len, len) {}
Square::Square(int len, int width) : Rectangle(len, width){
	if(GetLength() != GetWidth())
		std::cout << "Error, not a square...\n";
}
int main(){
	int choice;
	bool fQuit = false;
	Shape * sp;
	while(!fQuit){
		std::cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
		std::cin >> choice;
		switch(choice){
			case 0:		fQuit = true;
						break;
			case 1:		sp = new Circle(5);
						break;
			case 2: 	sp = new Rectangle(4,6);
						break;
			case 3: 	sp = new Square(5);
						break;
			default:	std::cout << "Please enter a number between 0 and 3\n";
						continue;
						break;
		}
		if(!fQuit)
			sp->Draw();
		delete sp;
		sp = 0;
		std::cout << std::endl;
	}
	return 0;
}

