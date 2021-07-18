// Listing 10.15 - Overload assignment (=) operator
#include <iostream>
class Cat{
	public:
		Cat();										// default constructor
		Cat(const Cat &);							// copy constructor
		~Cat();										// destructor
		
		int GetAge() const { return *itsAge; }
		int GetWeight() const { return *itsWeight; }
		void SetAge(int age) { *itsAge = age; }
		void SetWeight(int weight) { *itsWeight = weight; }
		Cat & operator=(const Cat &);
	private:
		int *itsAge;
		int *itsWeight;
};
Cat::Cat(){
	std::cout << "Entered constructor...\n";
	itsAge = new int;
	itsWeight = new int;
	*itsAge = 5;
	*itsWeight = 9;
	std::cout << "Returning to main...\n";
}
Cat::Cat(const Cat & rhs){
	std::cout << "Entered copy constructor...\n";
	itsAge = new int;
	itsWeight = new int;
	*itsAge = rhs.GetAge();
	*itsWeight = rhs.GetWeight();
	std::cout << "Returning to main...\n";
}
Cat::~Cat(){
	std::cout << "Entered destructor...\n";
	delete itsAge;
	itsAge = 0;
	delete itsWeight;
	std::cout << "Returning to main...\n";
	itsWeight = 0;
}
Cat & Cat::operator=(const Cat & rhs){
	std::cout << "Entered operator overload member function...\n";
	if(this == &rhs)
		return *this;
	*itsAge = rhs.GetAge();
	*itsWeight = rhs.GetWeight();
	std::cout << "Returning to main...\n";
	return *this;
}
int main(){
	std::cout << "Declaring a cat Frisky using Cat Frisky and using default values in the constructor to instantiate it...\n";
	Cat Frisky;
	std::cout << "Using Frisky.GetAge() we see that Frisky is " << Frisky.GetAge() << " years old.\n";
	std::cout << "Setting Frisky's age to 6 using Frisky.SetAge(6)...\n";
	Frisky.SetAge(6);
	std::cout << "Declaring a new cat Whiskers using Cat Whiskers and using default values in the constructor to instantiate it...\n";
	Cat Whiskers;
	std::cout << "Using Whiskers.GetAge() we see that Whiskers is " << Whiskers.GetAge() << " years old.\n";
	std::cout << "Using overloaded assignment operator Whiskers = Frisky...\n";
	Whiskers = Frisky;
	std::cout << "Using Whiskers.GetAge() we now see that Whiskers is " << Whiskers.GetAge() << " years old.\n";
	return 0;
}
