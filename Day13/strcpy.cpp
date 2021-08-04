// Listing 13.12 - Using strcpy()
#include <iostream>
#include <string.h>

int main(){
	std::cout << "Declaring String1[] = \"No man is an island\"...\n";
	char String1[] = "No man is an island";
	std::cout << "Declaring String2[80]...\n";
	char String2[80];
	std::cout << "Using strcpy(String2, String1)...\n";
	strcpy(String2, String1);
	std::cout << "String1: " << String1 << std::endl;
	std::cout << "String2: " << String2 << std::endl;
	return 0;
}
