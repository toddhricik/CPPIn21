// Listing 17.4 - Using cin.get() with no paramaters
#include <iostream>
int main(){
	char ch;
	puts("Enter a string:");
	while((ch=std::cin.get())!=EOF){
		std::cout << "ch: " << ch << std::endl;
	}
	std::cout << "Done!\n";
	return 0;
}
