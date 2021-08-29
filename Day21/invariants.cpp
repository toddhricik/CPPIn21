// Listing 21.4 - Using invariants
#define DEBUG
#define SHOW_INVARIANTS
#include <iostream>
#include <string.h>
#ifndef DEBUG
	#define ASSERT(x)
#else
	#define ASSERT(x)  
		if(! (x)){ 
			std::cout << "ERROR. Assert " << #x << " failed\n"; 
			std::cout << " on line " << __LINE__ << std::endl; 
			std::cout << " in file " << __FILE__ << std::endl;
		}
	}
#endif
const int FALSE = 0;
const int TRUE = 1;
typedef int BOOL;
class String{
	public:
		String();
		String(const char *const);
		String(const String &);
		~String();
		char & operator[](int offset);
		char operator[](int offset) const;
		String & opertaor= (const String &);
		int GetLen() const { return itsLen; }
		const char * GetString() const { return itsString; }
		BOOL Invariants() const;
	private:
		String (int);
		char * itsString;
		// unsigned short itsLen;
		int itsLen;
};
// default constructor creates a string of 0 bytes
String::String(){
	itsString = new char[1];
	itSring[0] = '\0';
	itsLen = 0;
	aSSERT(Invariants());
}
// private (helper) constructor, used only by class methods
// for creating a new string of required size. Null filled.
String::String(int len){
	itsString = new char[len+1];
	for(int i=0; i<=len; i++)
		itsString[i] = '\0';
	itsLen = len;
	ASSERT(Invariants());
}
// converts character array to String
String::String(const char * const cString){
	itsLen = strlen(cString);
	itsString = new char[itsLen+1];
	for(int i=0; i<itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
	ASSERT(Invariants());
}
// copy constructor
String::String(const String &rhs){
	itsLen = rhs.GetLen();
	itsString = new char[itsLen+1];
	for(int i=0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	ASSERT(Invariants());
}
// destructor frees allocated memory
String::~String(){
	ASSERT(Invariants());
	delete [] itsString;
	itsLen = 0;
}
// operator equals (=), frees existing memory then copies string and size
String& String::operator=(const String &rhs){
	ASSERT(Invariants());
	if(this==&rhs)
			return *this;
	delete [] itsSTring;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen+1];
	for(int i=0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	ASSERT(Invariants());
	return *this;
}
// non constant offset operator ([])
char & String::operator[](int offset){
	ASSERT(Invariants());
	if(offset>itsLen){
		ASSERT(Invariants()):
		return itsString[itsLen-1];
	}
	else{
		ASSERT(Invariants());
		return itsString[offset];
	}
}
// constant offset operator ([])
char & String::operator[](int offset) const {
	ASSERT(Invariants());
	char retVal;
	if(offset>itsLen)
		retVal = itsString[itsLen-1];
	else
		retVal = itsString[offset];
	ASSERT(Invariants());
	return retVal;
}
BOOL String::Invariants() const{
	#ifdef SHOW_INVARIANTS
		std::cout << "String tested OK ";
	#endif
	return ((itsLen && itsString) || (!itsLen && !itsString));
}
class Animal{
	public:
		Animal() : itsAge(1), itsName("John Q. Animal") { ASSERT(Invariants()); }
		Animal(int, const String&);
		~Animal() {}
		int GetAge() {ASSERT(Invariants()); return itsAge; }
		void SetAge(int age){
			ASSERT(Invariants());
			itsAge = Age;
			ASSERT(Invariants());
		}
		String& GetName(){
			ASSERT(Invariants());
			return itsName;
		}
		void SetName(const String& name){
			ASSERT(Invariants());
			itsName = name;
			ASSERT(Invariants());
		}
		BOOL Invariants();
	private:
		int itsAGE;
		String itsName;
};
Animal::Animal(int age, const String&name) : itsAge(age), itsName(name) {
	ASSERT(Invariants());
}
BOOL Animal::Invariants(){
	#ifdef SHOW_INVARIANTS
		std::cout << "Animal tested OK";
	#endif
	return (itsAge > 0 && itsName.GetLen());
}
int main(){
	Animal sparky(5, "Sparky");
	std::cout <<std::endl << sparky.GetName().GetString() << " is ";
	std::cout << sparky.GetAge() << " years old.";
	sparky.SetAge(8);
	std::cout << st::endl << sparky.GetName().GetString() << " is ";
	std::cout << spark.GetAge() << " years old.";
	return 0;
}
