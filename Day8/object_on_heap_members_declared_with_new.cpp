// Listing 8.6 - Pointers as data members
// accessed with -> operator

#include <iostream>

class SimpleCat
{
	public:
		SimpleCat();
		~SimpleCat();
		int GetAge() const { return *itsAge; }
		void SetAge(int age) { *itsAge = age; }
		int GetWeight() const { return *itsWeight; }
		void setWeight(int weight) { *itsWeight = weight; }

	private:
		int * itsAge;
		int * itsWeight;
};

SimpleCat::SimpleCat()
{
	itsAge = new int(2);
	itsWeight = new int(5);
}

SimpleCat::~SimpleCat()
{
	delete itsAge;
	itsAge = 0;
	delete itsWeight;
	itsWeight = 0;
}

int main()
{
	SimpleCat *Frisky = new SimpleCat;
	std::cout << "Frisky is " << Frisky->GetAge() << " years old " << std::endl;
	Frisky->SetAge(5);
	std::cout << "Freisky is " << Frisky->GetAge() << " years old " << std::endl;
	delete Frisky;
	Frisky = 0;
	return 0;
}
