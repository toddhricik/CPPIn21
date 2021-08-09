// Listing 14.3 - Demonstrates multiple inheritance
#include <iostream>
class Horse{
	public:
		Horse() { std::cout << "Horse constructor...\n"; }
		virtual ~Horse() { std::cout << "Horse destructor...\n"; }
		virtual void Whinny() const { std::cout << "Whinny!\n"; }
	private:
		int itsAge;
};
class Bird{
	public:
		Bird() { std::cout << "Bird constructor...\n"; }
		virtual ~Bird() { std::cout << "Bird destructor...\n"; }
		virtual void Chirp() const { std::cout << "Chirp!\n"; }
		virtual void Fly() const { std::cout << "Flying!\n"; }
	private:
		int itsWeight;
};
class Pegasus : public Horse, public Bird{
	public:
		void Chirp() const { Whinny(); } 
		Pegasus() { std::cout << "Pegasus constructor...\n"; }
		~Pegasus() { std::cout << "Pegasus destructor...\n"; }
		
};
const int MagicNumber = 2;
int main(){
	Horse * Ranch[MagicNumber];
	Bird * Aviary[MagicNumber];
	Horse * pHorse;
	Bird * pBird;
	int choice, i;
	for(i=0; i<MagicNumber; i++){
		std::cout << "\n(1)Horse (2)Pegasus: ";
		std::cin >> choice;
		if(choice==2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	for(i=0; i<MagicNumber; i++){
		std::cout << "\n(1)Bird (2)Pegasus: ";
		std::cin >> choice;
		if(choice==2)
			pBird = new Pegasus;
		else
			pBird = new Bird;
		Aviary[i] = pBird;
	}
	std::cout << std::endl;
	for(i=0; i<MagicNumber; i++){
		std::cout << "\nRanch[" << i << "]: ";
		Ranch[i]->Whinny();
		delete Ranch[i];
	}
	for(i=0; i<MagicNumber; i++){
		std::cout << "\nAviary[" << i << "]: ";
		Aviary[i]->Chirp();
		Aviary[i]->Fly();
		delete Aviary[i];
	}
	return 0;
}	
