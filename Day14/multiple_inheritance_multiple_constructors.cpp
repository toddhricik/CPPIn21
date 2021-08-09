// Listing 14.4 - Demonstrates multiple inheritance hwere base calsses have
// constructors have different signatures
#include <iostream>
typedef int HANDS;
enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };
class Horse{
	public:
		Horse(COLOR color, HANDS height);
		virtual ~Horse() { std::cout << "Horse destructor...\n"; }
		virtual void Whinny() const { std::cout << "Whinny!\n"; }
		virtual HANDS GetHeight() const { return itsHeight; }
		virtual COLOR GetColor() const { return itsColor; }
	private:
		HANDS itsHeight;
		COLOR itsColor;
};
Horse::Horse(COLOR color, HANDS height) : itsColor(color), itsHeight(height){
	std::cout << "Horse constructor...\n";
}
class Bird{
	public:
		Bird(COLOR color, bool migrates);
		virtual ~Bird() { std::cout << "Bird destructor...\n"; }
		virtual void Chirp() const { std::cout << "Chirp!\n"; }
		virtual void Fly() const { std::cout << "Flying...\n"; }
		virtual COLOR getColor() { return itsColor; }
		virtual bool GetMigration() { return itsMigration; }
	private:
		COLOR itsColor;
		bool itsMigration;
};
Bird::Bird(COLOR color, bool migrates) : itsColor(color), itsMigration(migrates){
	std::cout << "Bird constructor...\n";
}
class Pegasus : public Horse, public Bird{
	public:
		virtual void Chirp() const { Whinny(); }
		Pegasus(COLOR aColor, HANDS height, bool migrates, long NumBelieve);
		virtual ~Pegasus() { std::cout << "Pegasus destructor...\n"; }
		virtual long GetNumberBelievers() const { return itsNumberBelievers; }
	private:
		long itsNumberBelievers;
};
Pegasus::Pegasus(COLOR aColor, HANDS height, bool migrates, long NumBelieve) :
Horse(aColor, height), Bird(aColor, migrates), itsNumberBelievers(NumBelieve){
	std::cout << "Pegasus constructor...\n";
}
int main(){
	Pegasus *pPeg = new Pegasus(Red, 5, true, 10);
	pPeg->Fly();
	pPeg->Whinny();
	std::cout << "Your Pegasus is " << pPeg->GetHeight() << " hands tall and " << std::endl;
	if(pPeg->GetMigration())
		std::cout << "it does migrate.\n";
	else
		std::cout << "it does not migrate\n";
	std::cout << "A total of " << pPeg->GetNumberBelievers() << " people beilieve it exists.\n";
	delete pPeg;
	return 0;
}
