// Listing 20.2 - Use try/catch blocks
#include <iostream>
const int DefaultSize = 10;
int main(){
	int top = 90;
	int bottom = 0;
	try{
		// std::cout << "top / 2 = " << (top / 2) << std::endl;
		std::cout << "top / bottom = " << (top / bottom) << std::endl;
		// std::cout << "top / 3 = " << (top / 3) << std::endl;
	}
	catch (...){
		std::cout << "Something went wrong!\n";
	}
	std::cout << "Done.\n";
	return 0;
}
