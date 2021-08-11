// Listing 15.3 - Demonstrates how to access private static variable using non static member function.
#include <iostream>
class Cat{
	public:
		Cat(int age) : itsAge(age) { HowManyCats++; }
		virtual ~Cat() { HowManyCats--; }
		virtual int GetAge() const { return itsAge; }
		virtual void SetAge(int age) { itsAge = age; }
		virtual int GetHowMany() { return HowManyCats; }
	private:
		int itsAge;
		static int HowManyCats;
};
int Cat::HowManyCats = 0;
int main(){
	std::cout << "public virtual int GetHowMany() declared and defined in Cat class (non-static)...\n";
	std::cout << "private static int HowManyCats in Cat class...\n";
	std::cout << "int Cat::HowManyCats = 0 set above main()...\n";
	std::cout << "Setting const int MaxCats = 5...\n";
	const int MaxCats = 5;
	int i;
	std::cout << "Declaring an array of pointers to Cat objects on the heap using Cat *CatHouse[MaxCats]...\n";
	Cat *CatHouse[MaxCats];
	for(i=0; i<MaxCats; i++){
		std::cout << "Instantiating CatHouse[" << i << "] on heap using CatHouse[" << i << "] = new Cat(" << i << ")...\n"; 
		CatHouse[i] = new Cat(i);
	}
	for(i=0; i<MaxCats; i++){
		std::cout << "Using the public virtual int GetMany(): CatHouse[" << i << "]->GetHowMany() we see there are ";
		std::cout << CatHouse[i]->GetHowMany();
		std::cout << " cats left.\n";
		std::cout << "Now lets delete a cat that is ";
		std::cout << CatHouse[i]->GetAge();
		std::cout << " years old...\n";
		delete CatHouse[i];
		CatHouse[i] = 0;
	}
	return 0;
}
