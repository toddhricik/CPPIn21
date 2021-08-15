// Listing 15.11 - Demonstrates using an array of pointers to member functions
#include <iostream>
class Dog{
	public:
		void Speak() const { std::cout << "Woof!\n"; }
		void Move() const { std::cout << "Dog Move()\n"; }
		void Eat() const { std::cout << "Dog Eat()\n"; }
		void Growl() const { std::cout << "Dog Growl()\n"; }
		void Whimper() const { std::cout << "Dog Whimper()\n"; }
		void RollOver() const { std::cout << "Dog RollOver()\n"; }
		void PlayDead() const { std::cout << "Dog PlayDead()\n"; }
};
typedef void (Dog::*PDF)() const;
int main(){
	const int MaxFuncs = 7;
	PDF DogFunctions[MaxFuncs] = { Dog::Speak, Dog::Move, Dog::Eat, Dog::Growl, Dog::Whimper, Dog::RollOver, Dog::PlayDead };
	Dog *pDog = 0;
	int Method;
	bool fQuit = false;
	while(!fQuit){
		std::cout << "(0)Quit (1)Speak (2)Move (3)Eat (4)Growl (5)Whimper (6)RollOver (7)PlayDead: ";
		std::cin >> Method;
		if(Method < 0 || Method > 7){
			std::cout << "Invalid entry: Please enter a number between 0 and 7\n";
			continue;
		}
		else{
			pDog = new Dog;
			(pDog->*DogFunctions[Method-1])();
			 delete pDog;
		}
	}
	return 0;
}
			
