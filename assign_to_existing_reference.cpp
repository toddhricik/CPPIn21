// Listing 9.3 - Reassigning a reference

#include <iostream>

int main()
{
	std::cout << "Declaring int intOne...\n"; 
	int intOne;
	std::cout << "Declaring int &rSomeRef and initializing to intOne\n";
	int &rSomeRef = intOne;

	std::cout << "Setting intOne to 5...\n";
	intOne = 5;
	std::cout << "intOne:\t" << intOne << std::endl;
	std::cout << "rSomeRef:\t" << rSomeRef << std::endl;
	std::cout << "&intOne:\t" << &intOne << std::endl;
	std::cout << "&rSomeRef:\t" << &rSomeRef << std::endl;

	std::cout << "Declaring int intTwo and initializing it to 8...\n";
	int intTwo = 8;
	std::cout << "Setting rSomeRef = intTwo...\n";
	rSomeRef = intTwo;
	std::cout << "intOne:\t" << intOne << std::endl;
	std::cout << "intTwo:\t" << intTwo << std::endl;
	std::cout << "rSomeRef:\t" << rSomeRef << std::endl;
	std::cout << "&intOne:\t" << &intOne << std::endl;
	std::cout << "&intTwo:\t" << &intTwo << std::endl;
	std::cout << "&rSomeRef:\t" << &rSomeRef << std::endl;
	return 0;
}
