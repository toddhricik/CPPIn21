// Listing 13.5 - Creating a multidimensional array
#include <iostream>
int main(){
	int SomeArray[2][5] = { {0,1,2,3,4}, {0,2,4,6,8} };
	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			std::cout << "SomeArray[" << i << "][" << j << "]: ";
			std::cout << SomeArray[i][j] << std::endl;
		}
	}
	return 0;
}
