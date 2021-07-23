// Listing 12.8 - Using virtual methods
#include <iostream>
class Mammal{
	public:
		Mammal():itsAge(1) { std::cout << "Mammal's Mammal() constructor...\n"; }
		virtual ~Mammal() { std::cout << "Mammal's vitural ~Mammal() destructor...\n"; }
		void Move() const { std::cout << "Mammal's Move() one step...\n"; }
		virtual void Speak() const { std::cout << "Mammal's virtual Speak()...\n"; }
	protected:
		int itsAge;
};
class Dog : public Mammal{
	public:
		Dog() { std::cout << "Dog's Dog() constructor...\n"; }
		virtual ~Dog() { std::cout << "Dog's virutal ~Dog() destructor...\n"; }
		void WagTail() const { std::cout << "Wagging tail using Dog's WagTail()...\n"; }
		void Speak() const { std::cout <<  "Woof! Using Dog's Speak()...\n"; }
		void Move() const { std::cout << "Dog's Move() moves 5 steps...\n"; }
};
int main(){
	std::cout << "Declaring and intantiating Mammal *pDog = new Dog...\n";
	Mammal *pDog = new Dog;
	std::cout << "Using pDog->Move()...\n";
	pDog->Move();
	std::cout << "using pDog->Spreak()...\n";
	pDog->Speak();
	return 0;
}
