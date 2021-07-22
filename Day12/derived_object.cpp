// Listing 12.2 - Simple inheritance
#include <iostream>
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal{
	public:
		Mammal():itsAge(2), itsWeight(5) {}
		~Mammal() {}
		int GetAge() const { return itsAge; }
		void SetAge(int age) { itsAge = age; }
		int GetWeight() const { return itsWeight; }
		void SetWeight(int weight) { itsWeight = weight; }
		void Speak() const { std::cout << "Mammal sound!\n"; }
		void Sleep() const { std::cout << "shhhh. I'm sleeping.\n" ; }
	protected:
		int itsAge;
		int itsWeight;
};
class Dog : public Mammal{
	public:
		Dog():itsBreed(GOLDEN) {}
		~Dog() {}
		BREED GetBreed() const { return itsBreed; }
		void SetBreed(BREED breed) { itsBreed = breed; }
		void WagTail() const { std::cout << "Tail wagging....\n"; }
		void BegForFood() const { std::cout << "Begging for food...\n"; }
	private:
		BREED itsBreed;
};
int main(){
	Dog Fido;
	Fido.Speak();
	Fido.WagTail();
	std::cout << "Fido is " << Fido.GetAge() << " years old\n";
	return 0;
}

