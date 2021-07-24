// Listing 13.4 - An array of objects
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
	Cat Litter[5];
	int i;
	for(i=0; i<5; i++)
		Litter[i].SetAge(2*i+1);
	for(i=0; i<5; i++){
		std::cout << "Cat #" << i+1 << ": ";
		std::cout << Litter[i].GetAge() << " years old...\n";
	}
	return 0;
}
