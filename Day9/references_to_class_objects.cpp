// Listing 9.4 - References to class objects

#include <iostream>

class SimpleCat
{
	public:
		SimpleCat(int age, int weight);
		~SimpleCat() {}
		int GetAge() { return itsAge; }
		int GetWeight() { return itsWeight; }
	private:
		int itsAge;
		int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight)
{
	itsAge = age;
	itsWeight = weight;
}

int main()
{
	std::cout << "Declaring and instantiating SimpleCat Frisky(5,8)...\n";
	SimpleCat Frisky(5,8);
	std::cout << "Declaring the reference rCat and instantiating it with Frisky...\n";
	SimpleCat & rCat = Frisky;

	std::cout << "Using Frisky.GetAge(), Frisky is " << Frisky.GetAge() << " years old.\n";
	std::cout << "Using rCat.GetAge(), Frisky is " << rCat.GetAge() << " years old.\n";
	return 0;
}
