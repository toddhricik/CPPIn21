// Listing 10.5 - Copy constructors
#include <iostream>

class Cat{
	public:
		Cat();
		Cat(const Cat &);			// copy constructor
		~Cat();
		int GetAge() const { return *itsAge; }
		int GetWeight() const { return *itsWeight; }
		void SetAge(int age) { *itsAge = age; }
	private:
		int *itsAge;
		int *itsWeight;
};
Cat::Cat(){
	itsAge = new int;
	itsWeight = new int;
	*itsAge = 5;
	*itsWeight = 9;
}
Cat::Cat(const Cat & rhs){
	itsAge = new int;
	itsWeight = new int;
	*itsAge = rhs.GetAge();			// accesses public member function to get private data
	*itsWeight = *(rhs.itsWeight);	// accesses private member data via reference
}
Cat::~Cat(){
	delete itsAge;
	itsAge = 0;
	delete itsWeight;
	itsWeight = 0;
}
int main(){
	std::cout << "Declaring a cat Frisky using Cat Frisky...\n";
	Cat Frisky;
	std::cout << "Setting Frisky's age to 6 using Frisky.SetAge(6)...\n";
	Frisky.SetAge(6);
	std::cout << "Declare and instantiate a new cat, Boots using Frisky's copy constructor Cat Boots(Frisky)...\n";
	Cat Boots(Frisky);
	std::cout << "Using Frisky.GetAge() we see that Frisky is " << Frisky.GetAge() << " years old.\n";
	std::cout << "Using Boots.GetAge() we see that Boots is " << Boots.GetAge() << " years old.\n";
	std::cout << "Using Frisky.SetAge(7)...\n";
	Frisky.SetAge(7);
	std::cout << "\n\nUsing Frisky.GetAge() we see that Frisky is " << Frisky.GetAge() << " years old.\n";
    	std::cout << "Using Boots.GetAge() we see that Boots is " << Boots.GetAge() << " years old.\n";
	return 0;
}
