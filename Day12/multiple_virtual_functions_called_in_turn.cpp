// Listing 12.9 - Multiple virtual functions called in turn
#include <iostream>
class Mammal{
	public:
		Mammal():itsAge(1) {}
		virtual ~Mammal() {}
		virtual void Speak() const { std::cout << "Mammal's virtual Speak() speak!\n"; }
	protected:
		int itsAge;
};
class Dog : public Mammal{
	public:
		void Speak() const { std::cout << "Dog's Speak() Woof!!\n"; }
};
class Cat : public Mammal{
	public:
		void Speak() const { std::cout << "Cat's Speak() Meow!!\n"; }
};
class Horse : public Mammal{
	public:
		void Speak() const { std::cout << "Horse's Speak() Winnie!!\n"; }
};
class Pig : public Mammal{
	public:
		void Speak() const { std::cout << "Pig's Speak() Oink!!\n"; }
};
int main(){
	std::cout << "Declaring an array of Mammals using Mammal * theArray[5]...\n";
	Mammal * theArray[5];
	std::cout << "Declaring a pointer to a Mammal type using Mammal * ptr...\n";
	Mammal * ptr;
	int choice, i;
	for(i=0; i<5; i++){
		std::cout << "Enter a number... (1)dog (2)cat (3)horse (4)pig: ";
		std::cin >> choice;
		switch(choice){
			case 1: std::cout << "Instantiating a new Dog on the heap using ptr = new Dog...\n";
					ptr = new Dog;
					break;
			case 2: std::cout << "Instantiating a new Cat on the heap using ptr = new Cat...\n";
					ptr = new Cat;
					break;
			case 3: std::cout << "Instantiating a new Horse on the heap using ptr = new Horse...\n";
					ptr = new Horse;
					break;
			case 4: std::cout << "Instantiating a new Pig on the heap using ptr = New pig...\n";
					ptr = new Pig;
					break;
			default: std::cout << "Default behavior invoked to instantiate a new Mammal on the heap using ptr = new Mammal...\n";
					 ptr = new Mammal;
					 break;
		}
		theArray[i] = ptr;
	}
	std::cout << "Looping through each of theArray and calling theArray[i]->Speak() on the object at index i of theArray...\n";
	for(i=0; i<5; i++){
		std::cout << "Index " << i << ": ";
       		theArray[i]->Speak();
		std::cout << std::endl;
	}
	return 0;
}


