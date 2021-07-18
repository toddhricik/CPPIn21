// Listing 10.17 - Using constructor as a conversion operator
#include <iostream>
class Counter{
	public:
		Counter();						// default constructor
		Counter(int val);				// this constructor acts as a conversion operator
		~Counter() {}					// destructor
		int GetItsVal() const { return itsVal; }
		void SetItsVal(int x) { itsVal = x; }
	private:
		int itsVal;
};
Counter::Counter():itsVal(0) {}
Counter::Counter(int val):itsVal(val) {}
int main(){
	std::cout << "Declaring and instantiating an int theInt = 5...\n";
	int theInt = 5;
	std::cout << "Declaring and instantiating a Counter using Counter theCtr = the Int...\n";
	Counter Ctr = theInt;
	std::cout << "Using Ctr.GetItsVal() we see that instead of Ctr being instiated to the default (0)...\n";
	std::cout << "it was instead instantiated to " << Ctr.GetItsVal() << std::endl;
	return 0;
}
