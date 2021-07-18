// Listing 10.18 - Conversion operators
#include <iostream>
class Counter{
	public:
		Counter();									// default constructor
		Counter(int val);							// constructor for type conversion int -> Counter
		~Counter() {}								// destructor
		int GetItsVal() const { return itsVal; }
		void SetItsVal(int x) { itsVal = x; }
		operator int();								// conversion operator for Counter -> int
	private:
		int itsVal;
};
Counter::Counter():itsVal(0) {}
Counter::Counter(int val):itsVal(val) {}
Counter::operator int(){
	return (int(itsVal));
}
int main(){
	std::cout << "Declaring and instantiating Counter ctr(5)...\n";
	Counter ctr(5);
	std::cout << "Using ctr.GetItsVal() we see that itsVal is " << ctr.GetItsVal() << std::endl;
	std::cout << "Declaring and instantiating int theInt = ctr using the conversion operator...\n";
	int theInt = ctr;
	std::cout << "We see that theInt is equal to " << theInt << std::endl;
	return 0;
}
