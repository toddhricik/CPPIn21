// Listing 12.11 - Using a virtual Clone() method as a virtual copy constructor
#include <iostream>
class Mammal{
	public:
		Mammal():itsAge(1) { std::cout << "Mammal() constructor...\n"; }
		virtual ~Mammal() { std::cout << "virtual ~Mammal() destructor...\n"; }
		Mammal(const Mammal & rhs):itsAge(rhs.GetAge()){		// copy constructor
			std::cout << "Mammal copy constructor...\n";
	   	}
		virtual Mammal* Clone(){
			std::cout << "virtual Mammal* Clone()...\n";
			return new Mammal(*this);
		}
		virtual void Speak() const { std::cout << "Mammal's virtual Speak()...\n"; }
		int GetAge() const { return itsAge; }
	protected:
		int itsAge;
};
class Dog : public Mammal{
	public:
		Dog() { std::cout << "Dog() constructor...\n"; }
		virtual ~Dog() { std::cout << "virtual ~Dog() destructor...\n"; }
		Dog(const Dog & rhs):Mammal(rhs) { std::cout << "Dog copy constructor...\n"; }		// copy constructor
		virtual Mammal* Clone(){
			std::cout << "Dog's virtual Mammal* Clone()...\n";
			return new Dog(*this);
		}
		virtual void Speak() const { std::cout << "Dog's virtual Speak() Woof!\n"; } 

};
class Cat : public Mammal{
	public:
		Cat() { std::cout << "Cat() constructor...\n"; }
		virtual ~Cat() { std::cout << "virtual ~Cat() destructor...\n"; }
		Cat(const Cat & rhs):Mammal(rhs) { std::cout << "Cat copy constructor...\n"; }
		virtual Mammal* Clone(){
			std::cout << "Cat's virtual Mammal* Clone()...\n";
			return new Cat(*this);
		}
		virtual void Speak() const { std::cout << "Cat's virtual Speak() Meow!\n"; }
};
enum ANIMALS { MAMMAL, DOG, CAT };
const int NumAnimalTypes = 3;
int main(){
	std::cout << "Declaring a pointer to an array of Mammals using Mammal *theArray[NumAnimalTypes]...\n";
	Mammal *theArray[NumAnimalTypes];
	std::cout << "Declaring a pointer to a Mammal using Mammal* ptr...\n";
	Mammal* ptr;
	int choice, i;
	for(i=0; i<NumAnimalTypes; i++){
		std::cout << "(1)Dog (2)Cat (3)Mammal\n";
		std::cin >> choice;
		switch(choice){
			case DOG:	std::cout << "instantiating ptr = new Dog...\n";
						ptr = new Dog;
						break;
			case CAT:	std::cout << "Instantiating ptr = new Cat...\n";
						ptr = new Cat;
						break;
			default:	std::cout << "Instantiating ptr = new Mammal...\n";
						ptr = new Mammal;
						break;
		}
		theArray[i] = ptr;
	}
	std::cout << "Declaring a pointer to an array of Mammals using Mammal *OtherArray[NumAnimalTypes]...\n";
	Mammal *OtherArray[NumAnimalTypes];
	for(i=0; i<NumAnimalTypes; i++){
		std::cout << "Using theArray[" << i << "]->Speak()...\n";
		theArray[i]->Speak();
		std::cout << "Using OtherArray[" << i << "] = theArray[" << i << "]->Clone()...\n";
		OtherArray[i] = theArray[i]->Clone();
	}
	for(i=0; i<NumAnimalTypes; i++){
		std::cout << "Using OtherArray[" << i << "]->Speak()...\n";
		OtherArray[i]->Speak();
	}
	return 0;
}
