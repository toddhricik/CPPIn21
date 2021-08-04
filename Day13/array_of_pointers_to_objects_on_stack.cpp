// Listing 13.6 - Demonstrates an array of pointers to objects
#include <iostream>
class Cat{
	public:
		Cat() { itsAge = 1; itsWeight = 5; }
		~Cat() {}
		int GetAge() const { return itsAge; }
		int GetWeight() const { return itsWeight; }
		void SetAge(int age) { itsAge = age; }
	private:
		int itsAge;
		int itsWeight;
};
int main(){
	Cat * Family[500];
	int i;
	Cat *pCat;
	for(i=0; i<500; i++){
		pCat = new Cat;
		pCat->SetAge(2*i+1);
		Family[i] = pCat;
	}
	for(i=0; i<500; i++){
		std::cout << "Cat #" << i+1 << ": ";
		std::cout << Family[i]->GetAge() << std::endl;
	}
	return 0;
}
