// Listing 12.6 - Hiding overrided methods
#include <iostream>
class Mammal{
	public:
		void Move() const { std::cout << "Mammal's Move() one step.\n"; }
		void Move(int distance) const {	std::cout << "Mammal's Move(int distance) " << distance << " steps.\n"; }
	protected:
		int itsAge;
		int itsWeight;
};
class Dog : public Mammal{
	public:
		// You might get a warning that you are hiding a function
		void Move() const { std::cout << "Dog's Move() five steps.\n"; }
};
int main(){
	std::cout << "Declaring Mammal bigAnimal...\n";
	Mammal bigAnimal;
	std::cout << "Declaring Dog Fido...\n";
	Dog Fido;
	std::cout << "Using bigAnimal.Move()....\n";
	bigAnimal.Move();
	std::cout << "Using bigAnimal.Move(2)...\n";
	bigAnimal.Move(2);
	std::cout << "Using Fido.Move()...\n";
	Fido.Move();
	std::cout << "Using Fido.Move(10) will cause and error because Dog overrides Mammal Move(), but does not override Mammal(int distance)...\n";
	// Fido.Move(10);
	return 0;
}

