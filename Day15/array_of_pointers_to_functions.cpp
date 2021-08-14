// Listing 15.7 - Demonstrates using an array of pointers to functions
#include <iostream>
void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);
int main(){
	const int MaxArray = 5;
	int i;
	void (* pFuncArray[MaxArray])(int &, int &);
	bool fQuit = false;
	int valOne = 1;
	int valTwo = 2;
	int choice;
	for(i=0; i<MaxArray; i++){
		std::cout << "(0) Quit (1)Change Values (2)Square (3)Cube (4)Swap: \n";
		std::cin >> choice;
		switch(choice){
			case 1: 		pFuncArray[i] = GetVals;
							break;
			case 2:			pFuncArray[i] = Square;
							break;
			case 3:			pFuncArray[i] = Cube;
							break;
			case 4:			pFuncArray[i] = Swap;
							break;
			default:		pFuncArray[i] = 0;
							break;
		}
	}
	for(i=0; i<MaxArray; i++){
		if(pFuncArray[i]==0)
			continue;
		pFuncArray[i](valOne, valTwo);
		PrintVals(valOne, valTwo);	
	}
	return 0;
}
void PrintVals(int x, int y){
	std::cout << "x: " << x << " y: " << y << std::endl;
}
void Square(int & rX, int & rY){
	rX *= rX;
	rY *= rY;
}
void Cube(int &rX, int &rY){
	int tmp;
	tmp = rX;
	rX *= rX;
	rX = rX * tmp;

	tmp = rY;
	rY *= rY;
	rY = rY * tmp;
}
void Swap(int & rX, int &rY){
	int temp;
	temp = rX;
	rX = rY;
	rY = temp;
}
void GetVals(int &rValOne, int &rValTwo){
	std::cout << "Enter new value for ValOne: ";
	std::cin >> rValOne;
	std::cout << "New value for ValTwo: ";
	std::cin >> rValTwo;
}
