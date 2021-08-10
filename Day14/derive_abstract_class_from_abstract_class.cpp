// Listing 14.10 - Demonstrates how to derive abstract class from another abstract class
#include <iostream>
enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };
class Animal{													// common base class to both Mammal and Fish classes
	public:
		Animal(int);
		virtual ~Animal() { std::cout << "Animal destructor...\n"; }
		virtual int GetAge() const { return itsAge; }
		virtual void SetAge(int age) { itsAge = age; }
		virtual void Sleep() const = 0;
		virtual void Eat() const = 0;
		virtual void Reproduce() const = 0;
		virtual void Move() const = 0;
		virtual void Speak() const = 0;
	private:
		int itsAge;
};
Animal::Animal(int age) : itsAge(age){
	std::cout << "Animal constructor...\n";
}
class Mammal : public Animal{
	public:
		Mammal(int age) : Animal(age) { std::cout << "Mammal constructor...\n"; }
		virtual ~Mammal() { std::cout << "Mammal destructor...\n"; }
		virtual void Reproduce() const { std::cout << "Mammal reproducing...\n"; }
};
class Fish : public Animal{
	public:
		Fish(int age) : Animal(age) { std::cout << "Fish constsructor...\n"; }
		virtual ~Fish() { std::cout << "Fish destructor...\n"; }
		virtual void Sleep() const { std::cout << "Fish sleeping...\n"; }
		virtual void Eat() const { std::cout << "Fish eating...\n"; }
		virtual void Reproduce() const { std::cout << "Fish reproducing...\n"; }
		virtual void Move() const { std::cout << "Fish moving...\n"; }
		virtual void Speak() const {}
};
class Horse : public Mammal{
	public:
		Horse(int age, COLOR color) : Mammal(age), itsColor(color){	std::cout << "Horse constructor...\n"; }
		virtual ~Horse() { std::cout << "Horse destructor...\n"; }
		virtual void Speak() const { std::cout << "Whinny!\n"; }
		virtual COLOR GetItsColor() const { return itsColor; }
		virtual void Sleep() const { std::cout << "Horse sleeping...\n"; }
		virtual void Eat() const { std::cout << "Horse eating...\n"; }
		virtual void Move() const { std::cout << "Horse moving...\n"; }
	protected:
		COLOR itsColor;
};
class Dog : public Mammal{
	public:
		Dog(int age, COLOR color) : Mammal(age), itsColor(color) { std::cout << "Dog constructor...\n"; }
		virtual ~Dog() { std::cout << "Dog destructor...\n"; }
		virtual void Speak() const { std::cout << "Dog speaking...\n"; }
		virtual void Sleep() const { std::cout << "Dog sleeping...\n"; }
		virtual void Eat() const { std::cout << "Dog eating...\n"; }
		virtual void Move() const { std::cout << "Dog moving...\n"; }
		virtual void Reproduce() const { std::cout << "Dog reproducing...\n"; }
	protected:
		COLOR itsColor;
};
int main(){
	Animal * pAnimal=0;
	int choice;
	bool fQuit = false;
	while(fQuit==false){
		std::cout << "(1)Dog (2)Horse (3)Fish (0)Quit: ";
		std::cin >> choice;
		switch(choice){
			case 0:		fQuit = true;
						break;	
			case 1:		pAnimal = new Dog(5, Brown);
						break;
			case 2:		pAnimal = new Horse(4, Black);
						break;
			case 3: 	pAnimal = new Fish(5);
						break;
			default:	std::cout << "Error: Enter a number between 0 and 3.\n";
						continue;
		}
		if(!fQuit){
			pAnimal->Speak();
			pAnimal->Eat();
			pAnimal->Reproduce();
			pAnimal->Move();
			pAnimal->Sleep();
			delete pAnimal;
			std::cout << std::endl;
		}
	}
	return 0;
}



