// Listing 8.5 - Accessing data members of objects on the heap
// usig the -> operator
#include <iostream>

class SimpleCat
{
	public:
		SimpleCat() { itsAge =2; }
		~SimpleCat() {}
		int GetAge() const { return itsAge; }
		void SetAge(int age) { itsAge = age; }
	private:
		int itsAge;
};

int main()
{
	SimpleCat * Frisky = new SimpleCat;
	std::cout << "Frisky is " << Frisky->GetAge() << " years old " << std::endl;
	Frisky->SetAge(5);
	std::cout << "Frisky is " << Frisky->GetAge() << " years old " << std::endl;
	delete Frisky;
	Frisky = 0;
	return 0;
}
