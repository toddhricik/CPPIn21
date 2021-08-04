// Listing 13.13 - Using strncpy()
#include <iostream>
#include <string.h>

int main(){
	std::cout << "Setting MaxLength of String to 80...\n";
	const int MaxLength = 80;
	std::cout << "Declaring char String1[] = \"No man is an island\"...\n";
	char String1[] = "No man is an island";
	std::cout << "Declaring char String2[MaxLength+1]...\n";
	char String2[MaxLength+1];
	std::cout << "Using strncpy(String2, String1, MaxLength)...\n";
	strcpy(String2, String1, MaxLength);
	std::cout << "String1: " << String1 << std::endl;
	std::cout << "String2: " << String2 << std::endl;
	return 0;
}
