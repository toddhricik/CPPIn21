// Listing 17.6 - Demonstrates cin.get() with character array
#include <iostream>
int main(){
	char stringOne[256];
	char stringTwo[256];
	std::cout << "Enter string one: ";
	std::cin.get(stringOne, 256);
	std::cout << "stringOne: " << stringOne << std::endl;
	std::cout << "Enter string two: ";
	std::cin >> stringTwo;
	std::cout << "stringTwo: " << stringTwo << std::endl;
	return 0;
}
