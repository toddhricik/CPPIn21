// Listing 12.7 - Calling a base method from an overridden methhod
#include <iostream>
class Mammal{
	public:
		void Move() const { std::cout << "Mammal's Move() one step...\n"; }
		void Move(int distance) const {	std::cout << "Mammal's Move(int distance) " << distance << " steps.\n"; }
	protected:
		int itsAge;
		int itsWeight;
};
class Dog : public Mammal{
	public:
		void Move() const { std::cout << "Dog's Move() uses Mammal's Move(3)\n"; }
};
int main(){
	std::cout << "Declaring Mammal bigAnimal...\n";
	Mammal bigAnimal;
	std::cout << "Declaring Dog Fido...\n";
	Dog Fido;
	std::cout << "Using bigAnimal.Move(2)...\n";
	bigAnimal.Move(2);
	std::cout << "Using Fido.Move(6) will cause an error because Dog overrides Mammal's Move() but not Mammal's Move(int distance)...\n";
	// Fido.Move(6);
	std::cout << "Using Fido.Mammal::Move(6) will work thourgh:0)...\n";
	Fido.Mammal::Move(6);
	return 0;
}
