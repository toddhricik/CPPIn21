// Listing 20.2 - using parentheses in macros
#include <iostream>
#define CUBE(a) ( (a) * (a) * (a) )
#define THREE(a) a * a * a
int main(){
	long x = 5;
	long y = CUBE(x);
	long z = THREE(x);
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
	long a = 5, b = 7;
	y = CUBE(a+b);
	z = THREE(a+b);
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
	return 0;
}
