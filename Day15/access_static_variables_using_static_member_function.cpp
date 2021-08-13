// Listing 15.4 - Demonstrates how to access static variables using static member functions. 
#include <iostream>
class Cat{
	public:
		Cat(int age) : itsAge(age) { HowManyCats++; }
		virtual ~Cat() { HowManyCats--; }
		virtual int GetAge() const { return itsAge; }
		virtual void SetAge(int age) { itsAge = age; }
		static int GetHowMany() { return HowManyCats; }					// can't be declared const becuase it is a static member function!!
	private:
		int itsAge;
		static int HowManyCats;
};
int Cat::HowManyCats = 0;
void TelepathicFunction();
int main(){
	std::cout << "private: static int HowManyCats declared above main()...\n";
	std::cout << "public static int GetHowMany() { return HowManyCats; } declared and defined above main()...\n";
	std::cout << "int Cat::HowManyCats = 0 instntiated above main()...\n";	
	std::cout << "Setting const int MaxCats = 5...\n";
	const int MaxCats = 5;
	std::cout << "Declaring a an array of Cats called CatHouse on the heap using Cat *CatHouse[MaxCats]...\n";
	Cat *CatHouse[MaxCats];
	int i;
	for(i=0; i<MaxCats; i++){
		std::cout << "Instantiating a new Cat on the heap using CatHouse[i] = new Cat(i)...\n";
		CatHouse[i] = new Cat(i);
		std::cout << "Calling TelePathicFunction()...\n";
		TelepathicFunction();
	}
	std::cout << "Now lets delet some Cats...\n";
	for(i=0; i<MaxCats; i++){
		std::cout << "Deleting CatHouse[" << i << "]...\n";
		delete CatHouse[i];
		std::cout << "Calling TelepathicFunction()...\n";
		TelepathicFunction();
	}
	return 0;
}
void TelepathicFunction(){
	std::cout << "Using Cat::HowManyCats() in TelepathicFunction() we see there are " << Cat::GetHowMany() << " cats in the CatHouse.\n";
}

