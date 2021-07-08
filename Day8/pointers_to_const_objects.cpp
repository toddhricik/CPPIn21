// Listing 8.10 - Using pointers with const methods

#include <iostream>

class Rectangle
{
	public:
		Rectangle();
		~Rectangle();
		void SetLength(int length) { itsLength = length; }
		int GetLength() const { return itsLength; }
		void SetWidth(int width) { itsWidth = width; }
		int GetWidth() const { return itsWidth; }

	private:
		int itsLength;
		int itsWidth;
};

Rectangle::Rectangle()
{
	itsWidth = 5;
	itsLength = 10;
}

Rectangle::~Rectangle(){}

int main()
{
	Rectangle * pRect = new Rectangle;					// Non const member functions allowed
	const Rectangle * pConstRect = new Rectangle;		// Non const member functions disallowed
	Rectangle * const pConstPtr = new Rectangle;		// Non const member fucntions allowed

	std::cout << "pRect width; " << pRect->GetWidth() << " feet" << std::endl;
	std::cout << "pConstRect width: " << pConstRect->GetWidth() << " feet" << std::endl;
	std::cout << "pConstPtr width: " << pConstPtr->GetWidth() << " feet" << std::endl;

	pRect->SetWidth(10);
	// pConstRect->SetWidth(10);						// non const member function SetWidth() not allowed
	pConstPtr->SetWidth(10);

	std::cout << "pRect width: " << pRect->GetWidth() << " feet\n";
	std::cout << "pConstRect width: " << pConstRect->GetWidth() << " feet\n";
	std::cout << "pConstPtr width: " << pConstPtr->GetWidth() << " feet\n";
	return 0;
}
