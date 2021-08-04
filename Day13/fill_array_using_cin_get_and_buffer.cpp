// Listing 13.11 - Fill an array using cin.get(buffer, buffersize)
#include <iostream>
int main(){
	std::cout << "Declaring char buffer[10]...\n";
	char buffer[10];
	std::cout << "Enter a string: ";
	std::cin.get(buffer, 10);						// get up to 10 characters or up to newline
	std::cout << "Here is the buffer: " << buffer << std::endl;
	return 0;
}
