// Listing 21.6 - using inline function instead of macro
#include <iostream>
inline unsigned long Square(unsigned long a) { return a * a; }
inline unsigned long Cube(unsigned long a) { return a * a * a; }
int main(){
	unsigned long x = 1;
	for(;;){
		std::cout << "Enter a number (0 to quit): ";
		std::cin >> x;
		if(x==0)
			break;
		std::cout << "You entered: " << x;
		std::cout << ". Square(" << x << "): ";
		std::cout << Square(x);
		std::cout << ". Cube(" << x << "): ";
		std::cout << Cube(x) << ". " << std::endl;
	}
	return 0;
}

