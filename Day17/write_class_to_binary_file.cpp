//Listing 17.18 Writing a Class to a File
#include <fstream>
#include <iostream>
class Animal{
	public:
		Animal(int weight,long days):itsWeight(weight),DaysAlive(days){}
		~Animal(){}
		int GetWeight()const { return itsWeight; }
		void SetWeight(int weight) { itsWeight = weight; }
		long GetDaysAlive()const { return DaysAlive; }
		void SetDaysAlive(long days) { DaysAlive = days; }
	private:
		int itsWeight;
		long DaysAlive;
};
int main(){
	char fileName[80];
	std::cout << "Please enter the file name: ";
	std::cin >> fileName;
	std::ofstream fout(fileName, std::ios::binary);
	if (!fout){
			std::cout << "Unable to open " << fileName << " for writing.\n";
		return(1);
	}
	Animal Bear(50,100);
	fout.write((char*) &Bear,sizeof Bear);
	fout.close();
	std::ifstream fin(fileName, std::ios::binary);
	if (!fin){
		std::cout << "Unable to open " << fileName << " for reading.\n";
		return(1);
	}
	Animal BearTwo(1,1);
	std::cout << "BearTwo weight: " << BearTwo.GetWeight() << std::endl;
	std::cout << "BearTwo days: " << BearTwo.GetDaysAlive() << std::endl;
	fin.read((char*) &BearTwo, sizeof BearTwo);
	std::cout << "BearTwo weight: " << BearTwo.GetWeight() << std::endl;
	std::cout << "BearTwo days: " << BearTwo.GetDaysAlive() << std::endl;
	fin.close();
	return 0;
}
