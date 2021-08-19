// Listing 17.16 - Using ofstream and ifstream to read and write to disk
#include <fstream>
#include <iostream>
int main(){
	char fileName[80];
	char buffer[255];								// for user input
	std::cout << "Enter a file name: ";
	std::cin >> fileName;
	std::ofstream fout(fileName);					// open file for wrtiting
	fout << "This line wrtiiten directly to the file...\n";
	std::cout << "Enter text for the file: ";
	std::cin.ignore(1, '\n');						// eat the new line after the file name
	std::cin.getline(buffer, 255);					// get the user's input
	fout << buffer << "\n";					// wrtie the user's input within the buffer to the file with end line
	fout.close();								// close the file and flush buffer
	std::ifstream fin(fileName);					// Now reopen the file which was just written
	std::cout << "Here is the contents of the file:\n";
	char ch;
	while(fin.get(ch))
		std::cout << ch;
	std::cout << "\n**End of file contents.**\n";
	fin.close();								// close the file
	return 0;
}
