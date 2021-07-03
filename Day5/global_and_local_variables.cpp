#include <iostream>
void myFunction();

int x = 5, y = 7;	// global variables
int main()
{
	std::cout << "x from main: " << x << std::endl;
	std::cout << "y from main: " << y << std::endl << std::endl;
	myFunction();
	std::cout << "Back from myFunction!" << std::endl << std::endl;
	std::cout << "x from main: " << x << std::endl;
			std::cout << "y from main: " << y << std::endl;
	return 0;
}

void myFunction()
{
	int y = 10;

	std::cout << "x from myFunction: " << x << std::endl;
	std::cout << "y from myFunction: " << y << std::endl << std::endl;
}
