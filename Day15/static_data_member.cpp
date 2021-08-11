// Listing 15.1 - Demonstrates static data member
#include <iostream>
class Cat{
	public:
		Cat(int age) : itsAge(age) { HowManyCats++; }
		virtual ~Cat() { HowManyCats--; }
		virtual int GetAge() const { return itsAge; }
		virtual void SetAge(int age) { itsAge = age; }
		static int HowManyCats;
	private:
		int itsAge;
};
int Cat::HowManyCats = 0;
int main(){
	std::cout << "Declaring and instantiating const int MaxCats = 5...\n";
	const int MaxCats = 5;
	int i;
	std::cout << "Declaring an array of pointers to a house of cats using Cat *CatHouse[MaxCats]...\n";
	Cat *CatHouse[MaxCats];
	for(i=0; i<MaxCats; i++){
		std::cout << "Instantiating a new cat on the heap using CatHouse[" << i << "] = new Cat(" << i << ")...\n";
		CatHouse[i] = new Cat(i);
	}
	for(i=0; i<MaxCats; i++){
		std::cout << "Using Cat::HowManyCats we see there are ";
	   	std::cout << Cat::HowManyCats;
		std::cout << " cats.\n";
		std::cout << "Let's delete the Cat that is ";
		std::cout << CatHouse[i]->GetAge();
		std::cout << " years old using delete CatHouse[" << i << "]...\n";
		delete CatHouse[i];
		CatHouse[i] = 0;
	}
	return 0;
}
