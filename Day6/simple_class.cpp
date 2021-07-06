// Demonstrates declaration of a class and
// definition of class methods

#include <iostream>

class Cat
{
	public:
		int GetAge();
		void SetAge(int age);
		void Meow();
	private:
		int itsAge;
};

// GetAge, Public accessor function
// returns value of itsAge member
int Cat::GetAge()
{
	return itsAge;
}

// Definition of SetAge, public\
// accessor function
// Sets itsAge member
void Cat::SetAge(int age)
{
	// set member variable itsAge to
	// value passed in by parameter age
	itsAge = age;
}

// definition of Meow method
// returns: void
// parameters: None
// action: Prints "meow" to screen
void Cat::Meow()
{
	std::cout << "Meow.\n";
}
// Create a cat, seti its age, have it
// meow, tell us its age, tehn meow again.

int main()
{
	Cat Frisky;
	Frisky.SetAge(5);
	Frisky.Meow();
	std::cout << "Frisky is a cat who is ";
	std::cout << Frisky.GetAge() << " years old.\n";
	Frisky.Meow();
	return 0;
}
