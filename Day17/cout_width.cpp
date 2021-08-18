// Listing 17.12 - Demonstrates the use of of cout.width()
#include <iostream>
int main(){
	std::cout << "Start >";
	std::cout.width(25);
	std::cout << 123 << "< End\n";
	std::cout << "Start >";
	std::cout.width(25);
	std::cout << 123 << "< Next >";
	std::cout << 456 << "< End\n";
	std::cout << "Start >";
	std::cout.width(4);
	std::cout << 123456 << "< Endl\n";
	return 0;
}
