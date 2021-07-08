// Listing *.1 Demonstrates address-of operator
// and addresses of local variables
#include <iostream>

int main()
{
	unsigned short shortVar=5;
	unsigned long longVar=65535;
	long sVar = -65535;

	std::cout << "shortVar:\t" << shortVar;
	std::cout << "\tAddress of shortVar in hex:\t";
	std::cout << &shortVar << std::endl;
	std::cout << "\t\t\tAddress of shortVar in dec:\t";
	std::cout << (long)&shortVar << std::endl;

	std::cout << "longVar:\t" << longVar;
	std::cout << "\tAddress of longVar in hex:\t";
	std::cout << &longVar << std::endl;
	std::cout << "\t\t\tAddress of longVar in dec:\t";
	std::cout << (long)&longVar << std::endl;

	std::cout << "sVar:\t\t" << sVar;
	std::cout << "\tAddress of Svar in hex:\t\t";
	std::cout << &sVar << std::endl;
	std::cout << "\t\t\tAddress of Svar in dec:\t\t";
	std::cout << (long)&sVar << std::endl;
	return 0;
}
