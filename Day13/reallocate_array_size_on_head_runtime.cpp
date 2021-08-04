// Listing 13.9 - Reallocate array size on heap at runtime
#include <iostream>
int main(){
	int AllocationSize = 5;
	std::cout << "Declaring an array of 5 ints to the heap using int * pArrayOfNumbers = new int[AllocationSize=5]...\n";
	int * pArrayOfNumbers = new int[AllocationSize];
	int ElementsUsedSoFar = 0;
	std::cout << "Setting MaximumElementsAllowed to AllocationSize=5...\n";
	int MaximumElementsAllowed = AllocationSize;
	int InputNumber = -1;

	std::cout << "Enter non-zero number to add it to an array on the heap.\n";
	std::cout << "Enter a non-positve (less than or equal to zero) to quit.\n";
	std::cout << std::endl << "Enter Next number: ";
	std::cin >> InputNumber;

	while(InputNumber > 0){
		pArrayOfNumbers[ElementsUsedSoFar++] = InputNumber;
		std::cout << "\nChecking if pArrayOfNumbers is full...\n";
		if(ElementsUsedSoFar == MaximumElementsAllowed){
			std::cout << "pArrayOfNumbers is full...\n";
			std::cout << "Declaring pLargerArray using int * pLargerArray = new int[MaximumElementsAllowed + AllocationSize]...\n";
			int * pLargerArray = new int[MaximumElementsAllowed + AllocationSize];
			std::cout << "Copying ints from pArrayOfNumbers to pLargerArray...\n";
			for(int CopyIndex=0; CopyIndex < MaximumElementsAllowed; CopyIndex++)
				pLargerArray[CopyIndex] = pArrayOfNumbers[CopyIndex];
			std::cout << "Deleting pArrayOfNumbers from Heap...\n";
			delete [] pArrayOfNumbers;
			std::cout << "Setting pArrayOfNumbers = pLargerArray...\n";
			pArrayOfNumbers = pLargerArray;
			std::cout << "Increasing MaximumElementsAllowed to " << MaximumElementsAllowed + AllocationSize << std::endl;
			MaximumElementsAllowed += AllocationSize;
		}
		std::cout << "\nEnter next number: ";
		std::cin >> InputNumber;
	}
	std::cout << "You are have finished entering numbers to the dynamically allocated array...\n";
	std::cout << "Here are the numbers you entered...\n";
	for(int Index =0; Index < ElementsUsedSoFar; Index++)
		std::cout << "pArrayofNumbers[" << Index << "] = " << pArrayOfNumbers[Index] << std::endl;
	return 0;
}
