// Listing 21.3 - A simple assert macro
#define DEGUB
#include <iostream>
#ifndef DEBUG
	#define ASSERT(X)
#else
	#define ASSERT(X) 
		if(!(x)){
			std::cout << "ERROR. Assert " << #x << " failed.\n";
			std::cout << " on line " << __LINE__ << std::endl;
			std::cout << " in file " << __FILE__ << std::endl;
		}
#endif
int main(){
	int x = 5;
	std::cout << "First assert: " << std::endl;
	ASSERT(x==5);
	std::cout << "Second assert: " << std::endl;
	ASSERT(x != 5);
	std::cout << "Done.\n";
	return 0;
}
