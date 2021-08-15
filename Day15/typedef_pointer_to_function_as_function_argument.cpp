// Listing 15.9 - Using typdef to make pointers to functions as function arguments more readable
#include <iostream>
void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
typedef void (*VPF)(int &, int &);
void PrintVals(VPF, int, int);
int main(){
	VPF pFunc;
	bool fQuit = false;
	int valOne = 1;
	int valTwo = 2;
	int choice;
	while(fQuit==false){
		std::cout << "(0) Quit (1)Change Values (2)Square (3)Cube (4)Swap: \n";
		std::cin >> choice;
		switch(choice){
			case 1: 		pFunc = GetVals;
							break;
			case 2:			pFunc = Square;
							break;
			case 3:			pFunc = Cube;
							break;
			case 4:			pFunc = Swap;
							break;
			default:		fQuit = true;
							break;
		}
		if(fQuit==false)
			PrintVals(pFunc, valOne, valTwo);
	}
	return 0;
}
void PrintVals(VPF pFunc, int x, int y){
	std::cout << "x: " << x << " y: " << y << std::endl;
	pFunc(x, y);
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
