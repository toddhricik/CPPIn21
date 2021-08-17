// Listing 17.1 - Demonstrates character strings and cin
#include <iostream>
int main(){
	int myInt;
	long myLong;
	double myDouble;
	float myFloat;
	unsigned int myUnsigned;
	std::cout << "Int: ";
	std::cin >> myInt;
	std::cout << "Long: ";
	std::cin >> myLong;
	std::cout << "Double: ";
	std::cin >> myDouble;
	std::cout << "Float: ";
	std::cin >> myFloat;
	std::cout << "Unsigned: ";
	std::cin >> myUnsigned;
	std::cout << "\n\nInt:\t" << myInt << std::endl;
	std::cout << "Long:\t" << myLong << std::endl;
	std::cout << "Double:\t" << myDouble << std::endl;
	std::cout << "Float:\t" << myFloat << std::endl;
	std::cout << "Unsigned:\t" << myUnsigned << std::endl;
	return 0;
}
