// Listing 9.10 - Passing pointers to objects

#include <iostream>

class SimpleCat
{
	public:
		SimpleCat();				// constructor
		SimpleCat(SimpleCat&);			// copy constructor
		~SimpleCat();				// destructor
};

SimpleCat::SimpleCat(){
	std::cout << "SimpleCat constructor called..\n";
}

SimpleCat::SimpleCat(SimpleCat&){
	std::cout << "SimpleCat copy constructor called...\n";
}

SimpleCat::~SimpleCat(){
	std::cout << "SimpleCat destructor called...\n";
}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat *theCat);

int main(){
	std::cout << "Declaring and instantiating a SimpleCat Frisky...\n";
	SimpleCat Frisky;
	std::cout << "Calling FunctionOne(Frisky) using pass by value...\n";
	FunctionOne(Frisky);
	std::cout << "Calling FunctionTwo(&Frisky) using pass by reference...\n";
	FunctionTwo(&Frisky);
	return 0;
}

// FunctionOne passes by value
SimpleCat FunctionOne(SimpleCat theCat){
	std::cout << "FunctionOne: Returning... \n";
	return theCat;
}

// FunctionTwo passes by reference
SimpleCat* FunctionTwo(SimpleCat *theCat){
	std::cout << "FunctionTwo: Returning... \n";
	return theCat;
}
