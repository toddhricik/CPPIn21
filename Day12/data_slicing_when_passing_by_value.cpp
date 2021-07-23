// Listing 12.10 - Data slicing when passing by value
#include <iostream>
class Mammal{
	public:
		Mammal():itsAge(1) { std::cout << "Mammal() constructor...\n"; }
		virtual ~Mammal() {}
		virtual void Speak() const { std::cout << "Mammal's virtual Speak()...\n"; }
	protected:
		int itsAge;
};
class Dog : public Mammal{
	public:
		Dog() { std::cout << "Dog() constructor...\n"; }
		void Speak() const { std::cout << "Dog's Speak() Woof!!\n"; }
};
class Cat: public Mammal{
	public:
		Cat() { std::cout << "Cat() constructor...\n"; }
		void Speak() const { std::cout << "Cat's Speak() Meow!!\n"; }
};
void ValueFunction(Mammal);
void PtrFunction(Mammal*);
void RefFunction(Mammal&);
int main(){
	std::cout << "Declaring Mammal* ptr=0...\n";
	Mammal* ptr = 0;
	int choice;
	while(1){
		bool fQuit = false;
		std::cout << "Enter a number: (1)Dog (2)Cat (0)Quit: ";
		std::cin >> choice;
		switch(choice){
			case 0:		std::cout << "Setting fQuit to true...\n";
						fQuit = true;
						break;
			case 1:		std::cout << "Instantiating ptr = new Dog...\n";
						ptr = new Dog;
						break;
			case 2: 	std::cout << "Instantiating ptr = new Cat...\n";
						ptr = new Cat;
						break;
			default:	std::cout << "Instantiating default ptr = new Mammal...\n";
						ptr = new Mammal;
						break;
		}
		if(fQuit == true)
			break;
		std::cout << "Calling PtrFunction(ptr)...\n";
		PtrFunction(ptr);
		std::cout << "Calling RefFunction(*ptr)...\n";
		RefFunction(*ptr);
		std::cout << "Calling ValueFunction(*ptr)...\n";
		ValueFunction(*ptr);
	}
	return 0;
}
void ValueFunction(Mammal MammalValue){
	std::cout << "Using MammalValue.Speak() in ValueFunction(ptr)...\n";
	MammalValue.Speak();
}
void PtrFunction(Mammal * pMammal){
	std::cout << "Using pMammal->Speak() in PtrFunction(ptr)...\n";
	pMammal->Speak();
}
void RefFunction(Mammal & rMammal){
	std::cout << "Using rMammal.Speak() in RefFunction(*ptr)...\n";
	rMammal.Speak();
}



