// Listing 17.13 - Demonstrates the use of cout.fill()
#include <iostream>
int main(){
	std::cout << "Start >";
	std::cout.width(25);
	std::cout << 123 << "< End\n";
	std::cout << "Start >";
	std::cout.width(25);
	std::cout.fill('*');
	std::cout << 123 << "< End\n";
	std::cout << "Start >";
	std::cout.width(25);
	std::cout << 456 << "< End\n";
	return 0;
}
