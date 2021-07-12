// Listing 9.12 - passing constant references to objects

#include <iostream>

class SimpleCat
{
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
	std::cout << "SimpleCat Constructor called...\n";
	itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&){
	std::cout << "SimpleCat Copy Constructor called...\n";
}

SimpleCat::~SimpleCat(){
	std::cout << "SimpleCat Destructor called...\n";
}

const SimpleCat & FunctionTwo(const SimpleCat & theCat);

int main(){
	std::cout << "Declaring and instantiating theCat using SimpleCat Frisky...\n";
	SimpleCat Frisky;
	std::cout << "Using Frisky.GetAge() to see that Frisky is " << Frisky.GetAge() << " years old.\n";
	std::cout << "Declaring and instantiating int age = 5 ...\n";
	int age = 5;
	std::cout << "Using Frisky.SetAge(age)...\n";
	Frisky.SetAge(age);
	std::cout << "Using Frisky.GetAge() to see that Frisky is " << Frisky.GetAge() << " years old.\n";
	std::cout << "Calling FunctionTwo(Frisky) on prototype const SimpleCat & FunctionTwo(const SimpleCat & theCat)...\n";
	FunctionTwo(Frisky);
	std::cout << "Back from FunctionTwo...\n";
	std::cout << "Using Frisky.GetAge() to see that Frisky is " << Frisky.GetAge() << " years old.\n";
	return 0;
}

// FunctionTwo passes a ref to a constant object
const SimpleCat & FunctionTwo(const SimpleCat & theCat){
	std::cout << "Entered FunctionTwo...\n";
	std::cout << "Using theCat.GetAge() to see that Frisky is " << theCat.GetAge() << " years old...\n";
	std::cout << "Using thedCatSetAge(8) will cause an error because non constant object members are not allowed...\n";
	// theCat.SetAge(8);   		// not allowed because theCat is a const
	std::cout << "Returning theCat...\n";
	return theCat;
}

