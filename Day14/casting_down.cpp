/* Listing 14.2 - Demonstrates the use of dynamic cast using
 * Real Time Type Identification (RTTI). */
#include <iostream>
enum TYPE { HORSE, PEGASUS };
class Horse{
	public:
		Horse() {}
		~Horse() {}
		virtual void Gallop() { std::cout << "Galloping...\n"; }
	private:
		int itsAge;
};
class Pegasus : public Horse{
	public:
		Pegasus() {}
		~Pegasus() {}
		virtual void Fly() { std::cout << "Flying...\n"; }
};
int main(){
	const int NumberHorses = 5;
	Horse *Ranch[NumberHorses];
	Horse *pHorse;
	int choice, i;
	for(i=0; i<NumberHorses; i++){
		std::cout << "(1)Horse (2)Pegasus: ";
		std::cin >> choice;
		if(choice==2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	std::cout << std::endl;
	for(i=0; i<NumberHorses; i++){
		Pegasus *pPeg = dynamic_cast<Pegasus*>(Ranch[i]);
		if(pPeg!=nullptr)
			pPeg->Fly();
		else
			std::cout << "This is a horse. Horses can't fly.\n";
		delete Ranch[i];
	}
	return 0;
}

