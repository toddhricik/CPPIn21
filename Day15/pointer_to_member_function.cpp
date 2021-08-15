// Listing 15.10 - Demonstrates using a pointer to member functions using virtual methods
#include <iostream>
class Mammal{
	public:
		Mammal() : itsAge(1) { std::cout << "Mammal() constructor...\n"; }
		virtual ~Mammal() { std::cout << "~Mammal() destructor ...\n"; }
		virtual void Speak() const = 0;										// pure virtual function
		virtual void Move() const = 0; 										// pure virtual function
	protected:
		int itsAge;
};
class Dog : public Mammal{
	public:
		void Speak() const { std::cout << "Dog Speak()\n"; }
		void Move() const { std::cout << "Dog Move()\n"; }
};
class Cat : public Mammal{
	public:
		void Speak() const { std::cout << "Cat Speak()\n"; }
		void Move() const { std::cout << "Cat Move()\n"; }
};
class Horse : public Mammal{
	public:
		void Speak() const { std::cout << "Horse Speak()\n"; }
		void Move() const { std::cout << "Horse Move()\n"; }
};
int main(){
	void (Mammal::*pFunc)() const = 0;
	Mammal *ptr = 0;
	int Animal;
	int Method;
	bool fQuit = false;
	while(fQuit==false){
		std::cout << "(0)Quit (1)Dog (2)Cat (3)Horse: ";
		std::cin >> Animal;
		switch(Animal){
			case 1:		ptr = new Dog;
						break;
			case 2: 	ptr = new Cat;
						break;
			case 3: 	ptr = new Horse;
						break;
			default:	fQuit = true;
						break;
		}
		if(fQuit==false){
			std::cout << "(1)Speak (2)Move: ";
			std::cin >> Method;
			switch(Method){
				case 1:	pFunc = Mammal::Speak;
						break;
				case 2:	pFunc = Mammal::Move;
						break;
				default:pFunc = Mammal::Move;
						break;
			}
			(ptr->*pFunc)();
			delete ptr;
		}
	}
	return 0;
}

