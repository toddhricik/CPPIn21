// Listing 12.3 - COnstructor and destrutor calls on derived object
#include <iostream>
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal{
	public:
		Mammal();
		~Mammal();
		int GetAge() const { return itsAge; }
		void SetAge(int age) { itsAge = age; }
		int GetWeight() const { return itsWeight; }
		void SetWeight(int weight) { itsWeight = weight; }
		void Speak() const { std::cout << "Mammal sound!\n"; }
		void Sleep() const { std::cout << "sshhh... I'm sleeping...\n"; }
	protected:
		int itsAge;
		int itsWeight;
};
class Dog : public Mammal{
	public:
		Dog();
		~Dog();
		BREED GetBreed() const { return itsBreed; }
		void SetBreed(BREED breed) { itsBreed = breed; }
		void WagTail() const { std::cout << "Tail wagging!\n"; }
		void BegForFood() const { std::cout << "Begging for food...\n"; }
	private:
		BREED itsBreed;
};
Mammal::Mammal():itsAge(3), itsWeight(5){
	std::cout << "Mammal constructor called...\n";
}
Mammal::~Mammal(){
	std::cout << "Mammal destructor called...\n";
}
Dog::Dog():itsBreed(GOLDEN){
	std::cout << "Dog constructor called...\n";
}
Dog::~Dog(){
	std::cout << "Dog destructor called...\n";
}
int main(){
	Dog Fido;
	Fido.Speak();
	Fido.WagTail();
	std::cout << "Fido is " << Fido.GetAge() << " years old.\n";
	return 0;
}

