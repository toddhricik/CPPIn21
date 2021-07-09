// Listing 9.2 - Demonstrating the use of references

#include <iostream>

int main()
{
	int intOne;
	int &rSomeRef = intOne;

	std::cout << "Setting intOne to 5...\n";
	intOne = 5;
	std::cout << "intONe: " << intOne << std::endl;
	std::cout << "rSomeRef: " << rSomeRef << std::endl;

	std::cout << "&intOne: " << &intOne << std::endl;
	std::cout << "&rSomeRef: " << &rSomeRef << std::endl;

	return 0;
}

