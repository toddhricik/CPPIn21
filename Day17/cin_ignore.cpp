// Listing 17.8 - Demonstrates the use of cin.ignore()
#include <iostream>
int main(){
	char stringOne[255];
	char stringTwo[255];
	std::cout << "Enter string one: ";
	std::cin.get(stringOne, 255);
	std::cout << "stringOne: " << stringOne << std::endl;
	std::cout << "Enter string two: ";
	std::cin.getline(stringTwo, 255);
	std::cout << "stringTwo: " << stringTwo << std::endl;
	std::cout << "Now try again...\n";
	std::cout << "Enter string one: ";
	std::cin.get(stringOne, 255);
	std::cout << "stringOne: " << stringOne << std::endl;
	std::cin.ignore(255, '\n');
	std::cout << "Enter string two: ";
	std::cin.getline(stringTwo, 255);
	std::cout << "stringTwo: " << stringTwo << std::endl;
	return 0;
}
