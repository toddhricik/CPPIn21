// Listing 13.7 - Parsing out words from a character string using pointer arithmetic
#include <iostream>
#include <ctype.h>
#include <string.h>

bool GetWord(char * theString, char * word, int & offset);

int main(){
	const int bufferSize = 255;
	char buffer[bufferSize+1];						// holds the entire string
	char word[bufferSize+1];						// holds a word
	int wordOffset = 0;								// start at the beginning

	std::cout << "Enter a string: ";
	std::cin.getline(buffer, bufferSize);
	while(GetWord(buffer, word, wordOffset)){
		std::cout << "Got this word: " << word << std::endl;
	}
	return 0;
}
bool GetWord(char * theString, char * word, int & wordOffset){
	if(theString[wordOffset] == 0)
		return false;
	
	char * p1, * p2;
	p1 = p2 = theString + wordOffset;				// point to the next word
	
	// eat leading spaces
	for(int i=0; i < (int)strlen(p1) && !isalnum(p1[0]); i++)
		p1++;

	// see if you have a word
	if(!isalnum(p1[0]))
		return false;

	// p1 now points to start of next word. point p2 there as well.
	p2 = p1;

	// March p2 to end of word
	while(isalnum(p2[0]))
		p2++;

	// p2 is now at the end of the word. p1 is at the beginning of the word.
	// Length of the word is the difference between p2 and p1.
	int len = int(p2 - p1);

	// Copy the word into the buffer
	strncpy(word, p1, len);

	// Null terminate the word buffer
	word[len] = '\0';

	// Now find the beginning of the next word
	for(int j=int(p2-theString); j < (int)strlen(theString) && !isalnum(p2[0]); j++)
		p2++;
	
	wordOffset = int(p2 - theString);
	return true;
}	
