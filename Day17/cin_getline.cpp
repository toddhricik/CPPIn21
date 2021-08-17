// Listing 17.7 - Using cin.getline()
#include <iostream>
int main(){
	char stringOne[256];
	char stringTwo[256];
	char stringThree[256];
	std::cout << "Enter string one: ";
	std::cin.getline(stringOne, 256);
	std::cout << "stringOne: " << stringOne << std::endl;
	std::cout << "Enter string two: ";
	std::cin >> stringTwo;
	std::cout << "stringTwo: " << stringTwo << std::endl;
	std::cout << "Enter string three: ";
	std::cin.getline(stringThree, 256);
	std::cout << "stringThree: " << stringThree << std::endl;
	return 0;
}
