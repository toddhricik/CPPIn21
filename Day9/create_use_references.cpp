// Listing 9.1 - Demonstrating the use of references

#include <iostream>

int main()
{
	int intOne;
	int &rSomeRef = intOne;

	std::cout << "Setting intOne to 5...\n";
	intOne = 5;
	std::cout << "intOne: " << intOne << std::endl;
	std::cout << "rSomeRef: " << rSomeRef << std::endl;

	std::cout << "Setting rSomeRef to 7...\n";
	rSomeRef = 7;
	std::cout << "intONe: " << intOne << std::endl;
	std::cout << "rSomeRef: " << rSomeRef << std::endl;

	return 0;
}
