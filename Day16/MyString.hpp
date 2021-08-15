// Listing 16.1 - MyString.hpp
#include <iostream>
#include <string.h>
class String{
	public:
		String();
		String(const char * const);
		String(const String &);
		~String();
		// overloaded operators
		char & operator[](int offset);
		char operator[](int offset) const;
		String operator+(const String&);
		void operator+=(const String&);
		String & operator=(const String &);
		// general accessors
		int GetLen() const { return itsLen; }
		const char * GetString() const { return itsString; }
		// static int ConstructorCount;
	private:
		String(int);											// private constructor
		char *itsString;
		unsigned short itsLen;
};
// default constructor creates string of 0 bytes
String::String(){
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
	// std::cout << "\tDefault string constructor\n";
	// ConstructorCount++;
}
// private (helper) constructor, used only by
// class methods for creating a new string of
// required size. null filled.
String::String(int len){
	itsString = new char[len+1];
	for(int i=0; i<=len; i++)
		itsString[i] = '\0';
	itsLen = len;
	// std::cout << "\tString(char*) constructor\n";
	// ContructorCount++;
}
// copy constructor
String::String(const String &rhs){
	itsLen = rhs.GetLen();
	itsString = new char[itsLen+1];
	for(int i=0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	// std::cout << "\tString(String&) constructor\n";
	// ConstructorCount++;
}
// destructor, frees allocated memory
String::~String(){
	delete [] itsString;
	itsLen = 0;
	// std::cout << "\tString destructor\n";
}
// operator equals, frees existing memory
// then copies string and size
String & String::operator=(const String & rhs){
	if(this==&rhs)
		return *this;
	delete [] itsString;
	itsLen=rhs.GetLen();
	itsString = new char[itsLen+1];
	for(int i=0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	return *this;
	// std::cout << "\tString operator=\n";
}
// non constant offset operator, returns
// reference to character so it can be changed
char & String::operator[](int offset){
	if(offset > itsLen)
		return itsString[itsLen-1];
	else
		return itsString[offset];
}
// constant offset operator (see copy constructor!)
char String::operator[](int offset) const{
	if(offset > itsLen)
		return itsString[itsLen-1];
	else
		return itsString[offset];
}
// + operator. Appends new string to the end of current string resulting in a new string
String String::operator+(const String &rhs){
	int totalLen = itsLen + rhs.GetLen();
	String temp(totalLen);
	int i, j;
	for(i=0; i<itsLen; i++)
		temp[i] = itsString[i];
	for(j=0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}
// operator +=, Appends to current string without creating new string
void String::operator+=(const String &rhs){
	unsigned short rhsLen = rhs.GetLen();
	unsigned short totalLen = itsLen + rhsLen;
	String temp(totalLen);
	int i, j;
	for(i=0; i<itsLen; i++)
		temp[i] = itsString[i];
	for(j=0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[i=itsLen];
	temp[totalLen] = '\0';
	*this = temp;
}
// int String::ConstructorCount = 0;
