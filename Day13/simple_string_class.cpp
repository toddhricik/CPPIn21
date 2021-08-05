// Listing 13.14 - Simple String class
#include <iostream>
#include <string.h>

class String{
	public:
		// constructors
		String();												// default constructor
		String(const char * const);								// converts char array to String
		String(const String &);									// copy constructor
		~String();												// default destructor
		// overloaded operators
		char & operator[](unsigned short offset);
		char operator[](unsigned short offset) const;
		String operator+(const String &);
		void operator+=(const String &);
		String & operator=(const String &);
		// General accessors
		unsigned short GetLen() const { return itsLen; }
		const char * GetString() const { return itsString; }
	private:
		String(unsigned short);									// private constructor
		char * itsString;
		unsigned short itsLen;
};
// Default constructor creates string of 0 bytes
String::String(){
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
}
// Private (helper) constructor, used only by
// class methods for creating a new string of
// required size. Null filled.
String::String(unsigned short len){
	itsString = new char[len+1];
	for(unsigned short i = 0; i<=len; i++)
		itsString[i] = '\0';
	itsLen = len;
}

// Converts a character array to a String
String::String(const char * cString){
	itsLen = strlen(cString);
	itsString = new char[itsLen+1];
	for(unsigned short i = 0; i<itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
}
// copy constructor
String::String(const String & rhs){
	itsLen = rhs.GetLen();
	itsString = new char[itsLen+1];
	for(unsigned short i = 0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
}
// destructor, frees allocated memory
String::~String(){
	delete [] itsString;
	itsString = nullptr;
	itsLen = 0;
}
// Overload assignment operator (=).
// Frees existing memory
// then copies string and size.
String & String::operator=(const String & rhs){
	if(this == &rhs)
		return *this;
	delete [] itsString;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen+1];
	for(unsigned short i=0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	return * this;
}
// Nonconstant offset operator, returns
// reference to character so that it can be
// changed!
char & String::operator[](unsigned short offset){
	if(offset > itsLen)
		return itsString[itsLen-1];
	else
		return itsString[offset];
}
// Constant offset operator for use
// on const objects (see copy constructor!)
char String::operator[](unsigned short offset) const{
	if(offset > itsLen)
		return itsString[itsLen-1];
	else
		return itsString[offset];
}
// Create new string by adding current
// string to existing rhs
String String::operator+(const String & rhs){
	unsigned short totalLen = itsLen + rhs.GetLen();
	String temp(totalLen);
	unsigned short i;
	for(i=0; i<itsLen; i++)
		temp[i] = itsString[i];
	for(unsigned short j=0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}
// Changes current string, returns nothing
void String::operator+=(const String & rhs){
	unsigned short rhsLen = rhs.GetLen();
	unsigned short totalLen = itsLen + rhsLen;
	String temp(totalLen);
	unsigned short i;
	for(i=0; i<itsLen; i++)
		temp[i] = itsString[i];
	for(unsigned short j=0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[i-itsLen];
	temp[totalLen] = '\0';
	*this = temp;
}
int main(){
	std::cout << "Declaring and Initializing String s1(\"initial test\")...\n";
	String s1("initial test");
	std::cout << "s1:\t" << s1.GetString() << std::endl;

	std::cout << "Declaring and Initializing char * temp = \"Hello World\"...\n";
	char * temp = "Hello World";
	std::cout << "Setting s1 = temp...\n";
	s1 = temp;
	std::cout << "s1:\t" << s1.GetString() << std::endl;
	
	std::cout << "Declaring char tempTwo[20]...\n";
	char tempTwo[20];
	std::cout << "Using strcpy(tempTwo, \"; nice to be here!\")...\n";
	strcpy(tempTwo, "; nice to be here!");
	std::cout << "Using s1 += tempTwo...\n";
	s1 += tempTwo;
	std::cout << "tempTwo:\t" << tempTwo << std::endl;
	std::cout << "s1:\t" << s1.GetString() << std::endl;
	
	std::cout << "s1[4]:\t" << s1[4] << std::endl;
	std::cout << "Setting s1[4] = 'x'...\n";
	s1[4] = 'x';
	std::cout << "s1:\t" << s1.GetString() << std::endl;

	std::cout << "s1[999]:\t" << s1[999] << std::endl;
	
	std::cout << "Declaring and initializing String s2(\" Another string\")...\n";
	String s2(" Another string");
	std::cout << "Declaring String s3...\n";
	String s3;
	std::cout << "Using s3 = s1 + s2...\n";
	s3 = s1 + s2;
	std::cout << "s3:\t" << s3.GetString() << std::endl;

	std::cout << "Declaring String s4...\n";
	String s4;
	std::cout << "Initializing s4 = \"Why does this work?\"...\n";
	s4 = "Why does this work?";
	std::cout << "s4:\t" << s4.GetString() << std::endl;
	return 0;
}


	


