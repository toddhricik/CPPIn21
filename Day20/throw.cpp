// Listing 20.3 - Throwing
#include <iostream>
const int DefaultSize = 10;
int main(){
	int top = 90;
	int bottom = 0;
	try{
		std::cout << "top / 2 = " << (top / 2) << std::endl;
		std::cout << "top / bottom = ";
		if(bottom==0)
			throw("Division by zero!");
		std::cout << (top / bottom) << std::endl;
		std::cout << "top / 3 = " << (top / 3) << std::endl;
	}
	catch(const char *ex){
		std::cout << "\n*** " << ex << " ***" << std::endl;
	}
	std::cout << "Done.\n";
	return 0;
}

