// Listing 17.17 - Appeding to the end of a file using fstream objects
#include <fstream>
#include <iostream>

int main(){
	char fileName[80];
	char buffer[255];
	std::cout << "Please enter a file name: ";
	std::cin >> fileName;
	std::ifstream fin(fileName);
	if(fin){																		// if file already exists
		std::cout << "The file name you entered exists and its contents are:\n";
		char ch;
		while(fin.get(ch))
			std::cout << ch;
		std::cout << "***End of file contents.***\n";
	}
	fin.close();
	std::cout << "\nOpening " << fileName << " in append mode...\n";
	std::ofstream fout(fileName, std::ios::app);
	if(!fout){
		std::cout << "Unable to open " << fileName << " for appending.\n";
		return 1;
	}
	std::cout << "\nEnter text for the file: ";
	std::cin.ignore(1, '\n');
	std::cin.getline(buffer, 255);
	fout << buffer << "\n";
	fout.close();
	fin.open(fileName);																// reassign existing fin object
	if(!fin){
		std::cout << "Unable to open " << fileName << " for reading.\n";
		return 1;
	}
	std::cout << "\nHere's the contents of the file:\n";
	char ch;
	while(fin.get(ch))
		std::cout << ch;
	std::cout << "\n***End of file contents.***\n";
	fin.close();
	return 0;
}
