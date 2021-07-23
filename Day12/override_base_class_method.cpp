// Listing 12.5 - Overriding a base class method in a derived class
#include <iostream>
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal{
	public:
		Mammal() { std::cout << "Mammal() constructor...\n"; }
		~Mammal() { std::cout << "~Mammal() destructor...\n"; }
		void Speak() const { std::cout << "Mammal sound!\n"; }
		void Sleep() const { std::cout << "sshhhhh... I'm sleeping...\n"; }
	protected:
		int itsAge;
		int itsWeight;
};
class Dog : public Mammal{
	public:
		Dog() { std::cout << "Dog() constructor...\n"; }
		~Dog() { std::cout << "~Dog() destructor...\n" ; }
		void WatTail() const { std::cout << "Tail wagging...\n"; }
		void BegForFood() const { std::cout << "Begging for food...\n"; }
		void Speak() const { std::cout << "Woof!\n"; }
	private:
		BREED itsBreed;
};
int main(){
	std::cout << "Declaring Mammal bigAnimal...\n";
	Mammal bigAnimal;
	std::cout << "Declaring Dog Fido...\n";
	Dog Fido;
	std::cout << "Using bigAnimal.Speak() we get ";
        bigAnimal.Speak();
	std::cout << std::endl;
	std::cout << "Using Fido.Speak() we get ";
       	Fido.Speak();
	std::cout << std::endl;
	return 0;
}

