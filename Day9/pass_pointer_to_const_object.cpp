// Listing 9.11 - Passing pointers to constant object

#include <iostream>

class SimpleCat{
	public:
		SimpleCat();
		SimpleCat(SimpleCat&);
		~SimpleCat();

		int GetAge() const { return itsAge; }
		void SetAge(int age) { itsAge = age; }
	
	private:
		int itsAge;
};

SimpleCat::SimpleCat(){
	std::cout << "SimpleCat constructor called...\n";
	itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&){
	std::cout << "SimpleCat copy constructor called...\n";
}
SimpleCat::~SimpleCat(){
	std::cout << "SimpleCat destructor called...\n";
}

const SimpleCat * const FunctionTwo(const SimpleCat * const theCat);

int main(){
	std::cout << "Declaring and instantiating a SimpleCat Frisky...\n";
	SimpleCat Frisky;
	std::cout << "Using Frisky.GetAge() to get Frisky's age...\n";
	std::cout << "Frisky is " << Frisky.GetAge() << " years old.\n";
	std::cout << "Declaring and instantiating an int age = 5...\n";
	int age = 5;
	std::cout << "Setting Frisky's age to 5 Using Frisky.SetAge(age)...\n";
	Frisky.SetAge(age);
	std::cout << "Frisky is " << Frisky.GetAge() << " years old...\n";
	std::cout << "Calling FuntionTwo(&Frisky) by passing a reference...\n";
	FunctionTwo(&Frisky);
	std::cout << "Using Frisky.GetAge(), Frisky is " << Frisky.GetAge() << " years old.\n";
	return 0;
}

// FunctionTwo: passes a const pointer
const SimpleCat * const FunctionTwo(const SimpleCat * const theCat){
	std::cout << "FunctionTwo: Returning...\n";
	std::cout << "Using theCat->GetAGe(): Frisky is now " << theCat->GetAge() << " years old.\n";
	// theCat-SetAge(8); 				// Causes an error because theCat was declared as a const SimpleCat
	return theCat;
}


