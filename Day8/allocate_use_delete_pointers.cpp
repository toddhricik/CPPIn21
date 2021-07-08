// Listing 8.4
// Allocating and deletin a pointer
#include <iostream>
int main()
{
	int localVariable = 5;
	int * pLocal = &localVariable;
	int * pHeap = new int;
	*pHeap = 7;
	std::cout << "localVariable: " << localVariable << std::endl;
	std::cout << "*pLocal: " << *pLocal << std::endl;
	std::cout << "*pHeap: " << *pHeap << std::endl;
	delete pHeap;
	pHeap = new int;
	*pHeap = 9;
	std::cout << "*pHeap: " << *pHeap << std::endl;
	delete pHeap;
	return 0;
}

