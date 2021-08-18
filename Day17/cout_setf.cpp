// Listing 17.14 - Demonstrates the use of cout.setf() to set iostream object state using flags
#include <iostream>
#include <iomanip>
int main(){
	const int number = 185;
	std::cout << "The number is " << number << std::endl;
	std::cout << "The number is " << std::hex << number << std::endl;
	std::cout.setf(std::ios::showbase);
	std::cout << "The number is " << std::hex << number << std::endl;
	std::cout << "The number is ";
	std::cout.width(10);
	std::cout << std::hex << number << std::endl;
	std::cout << "The number is ";
	std::cout.width(10);
	std::cout.setf(std::ios::left);
	std::cout << std::hex << number << std::endl;
	std::cout << "The number is ";
	std::cout.width(10);
	std::cout.setf(std::ios::internal);
	std::cout << std::hex << number << std::endl;
	std::cout << "The number is " << std::setw(10) << std::hex << number << std::endl;
	return 0;
}

