// Listing 14.6 - Demonstrates virtual inheritance
#include <iostream>
typedef int HANDS;
enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };
class Animal{													// common base class to horse and bird
	public:
		Animal(int);
		virtual ~Animal() { std::cout << "Animal destructor...\n"; }
		virtual int GetAge() const { return itsAge; }
		virtual void SetAge(int age) { itsAge = age; }
	private:
		int itsAge;
};
Animal::Animal(int age) : itsAge(age){
	std::cout << "Animal constructor...\n";
}
class Horse : virtual public Animal{
	public:
		Horse(COLOR color, HANDS height, int age);
		virtual ~Horse() { std::cout << "Horse destructor...\n"; }
		virtual void Whinny() const { std::cout << "Whinny!\n"; }
		virtual HANDS GetHeight() const { return itsHeight; }
		virtual COLOR GetColor() const { return itsColor; }
	protected:
		HANDS itsHeight;
		COLOR itsColor;
};
Horse::Horse(COLOR color, HANDS height, int age) : Animal(age), itsColor(color), itsHeight(height){
	std::cout << "Horse constructor...\n";
}
class Bird : virtual public Animal{
	public:
		Bird(COLOR color, bool migrates, int age);
		virtual ~Bird() { std::cout << "Bird destructor...\n"; }
		virtual void Chirp() const { std::cout << "Chirp!\n"; }
		virtual void Fly() const { std::cout << "Flying!\n"; }
		virtual COLOR GetColor() const { return itsColor; }
		virtual bool GetMigration() const { return itsMigration; }
	protected:
		COLOR itsColor;
		bool itsMigration;
};
Bird::Bird(COLOR color, bool migrates, int age) : Animal(age), itsColor(color), itsMigration(migrates){
	std::cout << "Bird constructor...\n";
}
class Pegasus : public Horse, public Bird{
	public:
		void Chirp() const { Whinny(); }
		Pegasus(COLOR color, HANDS height, bool migrates, long numBelievers, int age);
		virtual ~Pegasus() { std::cout << "Pegasus destructor...\n"; }
		virtual long GetNumberBelievers() const { return itsNumberBelievers; }
		virtual COLOR GetColor() const { return Horse::itsColor; }
	private:
		long itsNumberBelievers;
};
Pegasus::Pegasus(COLOR color, HANDS height, bool migrates, long NumBelieve, int age) :
Horse(color, height, age), Bird(color, migrates, age), Animal(age*2), itsNumberBelievers(NumBelieve){
	std::cout << "Pegasus constructor...\n";
}
int main(){
	Pegasus *pPeg = new Pegasus(Red, 5, true, 10, 2);
	int age = pPeg->GetAge();
	std::cout << "This pegasus is " << age << " years old.\n";
	delete pPeg;
	return 0;
}
