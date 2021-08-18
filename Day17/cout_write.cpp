// Listing 17.11 - Demonstrates the use of cout.write()
#include <iostream>
#include <string.h>
int main(){
	char One[] = "One if by land";
	int fullLength = strlen(One);
	int tooShort = fullLength - 4;
	int tooLong = fullLength + 6;
	std::cout.write(One, fullLength) << std::endl;
	std::cout.write(One, tooShort) << std::endl;
	std::cout.write(One, tooLong) << std::endl;
	return 0;
}
