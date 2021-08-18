// Listing 17.9 - using cin.peek() and cin.putback()
#include <iostream>
int main(){
	char ch;
	std::cout << "Enter a phrase: ";
	while((ch=std::cin.get()) != '\n'){
		if(ch=='!')
			std::cin.putback('$');
		else
			std::cout << ch;
		while(std::cin.peek() == '#')
			std::cin.ignore(1, '#');
	}
	return 0;
}
