// Listing 10.14 - Overload the plus (+) operator
#include <iostream>
class Counter{
	public:
		Counter();
		Counter(int initialValue);
		~Counter() {}
		int GetItsVal() const { return itsVal; }
		void SetItsVal(int x) { itsVal = x; }
		Counter operator+(const Counter &);
	private:
		int itsVal;
};
Counter::Counter():itsVal(0) {}
Counter::Counter(int initialValue):itsVal(initialValue) {}
Counter Counter::operator+(const Counter & rhs){
	return Counter(itsVal + rhs.GetItsVal());
}
int main(){
        std::cout << "Declaring and instantiating Counter varOne(2), varTwo(4), and just declaring Counter varThree...\n";
        Counter varOne(2), varTwo(4), varThree;
        varThree = varOne + varTwo;
        std::cout << "Using varThree = varOne + varTwo we see that varThree's itsVal is " << varThree.GetItsVal() << std::endl;
        return 0;
}	
