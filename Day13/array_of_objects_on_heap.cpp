// Listing 13.8 - Demonstrates an array of objects on the heap
#include <iostream>
class Cat{
	public:
		Cat() { itsAge = 1; itsWeight = 5; }
		~Cat() { std::cout << "Destructor ~Cat() called...\n"; }
		int GetAge() const { return itsAge; }
		int GetWeight() const { return itsWeight; }
		void SetAge(int age) { itsAge = age; }
	private:
		int itsAge;
		int itsWeight;
};
int main(){
	Cat * Family = new Cat[500];
	int i;
	for(i=0; i<500; i++)
		Family[i].SetAge(2*i+1);
	for(i=0; i<500; i++){
		std::cout << "Cat #" << i+1 << ": ";
		std::cout << Family[i].GetAge() << std::endl;
	}
	delete [] Family;
	return 0;
}
