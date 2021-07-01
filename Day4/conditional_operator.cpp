// Listing 4.9 - demonstrates the conditional operator
//
#include <iostream>
int main()
{
	int x, y, z;
	std::cout << "Enter two numbers.\n";
	std::cout << "First: ";
	std::cin >> x;
	std::cout << "\nSecond: ";
	std::cin >> y;
	std::cout << "\n";

	if (x>y)
		z = x;
	else
		z = y;

	std::cout << "After if test, z: " << z;
	std::cout << "\n";

	z = (x > y) ? x : y;
	
	std::cout << "After conditional test, z: " << z;
	std::cout << "\n";
	return 0;
}
