// Linsting 7.7
// Demonstrates the do while loop

#include <iostream>

int main()
{
	int counter;
	std::cout << "How many \"Hellos\" should I print? ";
	std::cin >> counter;
	do{
		std::cout << "Hello\n";
		counter--;
	}while(counter > 0);
	
	std::cout << "Counter is: " << counter << "\n";
	return 0;
}
