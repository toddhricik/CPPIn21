// Listing 9.8 - Returning multiple values from a function using pointers

#include <iostream>

short Factor(int n, int* pSquared, int* pCubed);

int main(){
	int number, squared, cubed;
	short error;

	std::cout << "Enter a number (0 - 20): ";
	std::cin >> number;

	error = Factor(number, &squared, &cubed);

	if(!error){
		std::cout << "number: " << number << "\n";
		std::cout << "square: " << squared << "\n";
		std::cout << "cubed: " << cubed << "\n";
	}
	else
		std::cout << "Error encountered!!\n";
	return 0;
}

short Factor(int n, int *pSquared, int *pCubed){
	short Value = 0;
	if(n > 20)
		Value = 1;
	else{
		*pSquared = n*n;
		*pCubed = n*n*n;
		Value = 0;
	}
	return Value;
}
