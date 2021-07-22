// Listing 12.4 - Overloading constructors in derived classes
#include <iostream>
enum BREED { GOLDEN, CAIRN, DNADIE, SHETLAND, DOBERMAN, LAB };
class Mammal{
	public:
		Mammal();
		Mammal(int age);
		~Mammal();
		int GetAge() const { return itsAge; }
		void SetAge(int age) { itsAge = age; }
		int GetWeight() const { return itsWeight; }
		void SetWeight(int weight) { itsWeight = weight; }
		void Speak() const { std::cout << "Mammal sound!\n"; }
		void Sleep() const { std::cout << "ssshh... I'm sleepoing\n"; }
	protected:
		int itsAge;
		int itsWeight;
};
class Dog : public Mammal{
	public:
		Dog();
		Dog(int age);
		Dog(int age, int weight);
		Dog(int age, BREED breed);
		Dog(int age, int weight, BREED breed);
		~Dog();
		void WagTail() const { std::cout << "Wagging tail!\n"; }
		void BegForFood() const { std::cout << "Begging for food...\n"; }
	private:
		BREED itsBreed;
};
Mammal::Mammal():itsAge(1), itsWeight(5){
	std::cout << "Mammal() constructor...\n";
}
Mammal::Mammal(int age):itsAge(age), itsWeight(5){
	std::cout << "Mammal(int age) constructor...\n";
}
Mammal::~Mammal(){
	std::cout << "~Mammal() destuctor...\n";
}
Dog::Dog() : Mammal(), itsBreed(GOLDEN){
	std::cout << "Dog() constructor...\n";
}
Dog::Dog(int age) : Mammal(age), itsBreed(GOLDEN){
	std::cout << "Dog(int age) constructor...\n";
}
Dog::Dog(int age, int weight) : Mammal(age), itsBreed(GOLDEN){
	itsWeight = weight;
	std::cout << "Dog(int age, int weight) constructor...\n";
}
Dog::Dog(int age, int weight, BREED breed) : Mammal(age), itsBreed(breed){
	itsWeight = weight;
	std::cout << "Dog(int age, int weight, BREED breed) constructor...\n";
}
Dog::Dog(int age, BREED breed) : Mammal(age), itsBreed(breed){
	std::cout << "Dog(int age, BREED breed) constructor...\n";
}
Dog::~Dog(){
	std::cout << "~Dog() destructor...\n";
}
int main(){
	std::cout << "Declaring Dog Fido...\n";
	Dog Fido;
	std::cout << "Fido is " << Fido.GetAge() << " years old and weighs " << Fido.GetWeight() << " pounds.\n";
        std::cout << "Declaring Dog Rover(5)...\n";	
	Dog Rover(5);
        std::cout << "Rover is " << Rover.GetAge() << " years old and weighs " << Rover.GetWeight() << " pounds.\n";
        std::cout << "Declaring Dog Buster(6, 8)...\n";	
	Dog Buster(6, 8);
        std::cout << "Buster is " << Buster.GetAge() << " years old and weighs " << Buster.GetWeight() << " pounds.\n";
        std::cout << "Declaring Dog YORKIE(3, GOLDEN)...\n";	
	Dog Yorkie(3, GOLDEN);
        std::cout << "Yorkie is " << Yorkie.GetAge() << " years old and weighs " << Yorkie.GetWeight() << " pounds.\n";
        std::cout << "Declaring Dog Dobbie(4, 20, DOBERMAN)...\n";	
	Dog Dobbie(4, 20, DOBERMAN);
        std::cout << "Dobbie is " << Dobbie.GetAge() << " years old and weighs " << Dobbie.GetWeight() << " pounds.\n";
        Fido.Speak();
	Rover.WagTail();
	return 0;
}

