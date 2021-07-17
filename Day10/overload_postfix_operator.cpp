// Listing 10.12 - Overload postfix ++ operator
#include <iostream>
class Counter{
	public:
		Counter();
		~Counter() {}
		int GetItsVal() const { return itsVal; }
		void SetItsVal(int x) { itsVal = x; }
		const Counter& operator++();				// a prefix operator
		const Counter operator++(int);				// a postfix operator (which is required to return by value)
	private:
		int itsVal;
};
Counter::Counter():itsVal(0){}
const Counter& Counter::operator++(){
	++itsVal;
	return *this;									// no temp object required and pass by reference is permitted
}
const Counter Counter::operator++(int theFlag){
	Counter temp(*this);							// temp object is required and provided by copy constructor
   	++itsVal;
	return temp;									// temp will go out of scope but "rhs" of copy constructor is incremented
}
int main(){
        std::cout << "Declaring and instantiating Counter i using the default initializer for itsVal in the constructor...\n";
        Counter i;
        std::cout << "Using i.GetItsVal() to see that i's itsval is " << i.GetItsVal() << std::endl;
        std::cout << "Using i++ to increment i's itsVal using the overloaded ++ prefix operator...\n";
        i++;
        std::cout << "Using i.GetItsVal() to see that i's itsval is " << i.GetItsVal() << std::endl;		
		std::cout << "Using ++i to increment i's itsVal using the overloaded ++ prefix operator...\n";
        ++i;
        std::cout << "Using i.GetItsVal() we see that i's itsVal is now " << i.GetItsVal() << std::endl;
        std::cout << "Declaring a new Counter \"a\" and intantiating it to ++i using the default copy constructor...\n";        Counter a = ++i;
        std::cout << "Using a.GetItsVal() we see that a's itsVal is " << a.GetItsVal() << std::endl;
        std::cout << "Using i.GetItsVal() we see that i's itsVal was incremented to " << i.GetItsVal() << std::endl;
		std::cout << "Using a=i++ to increment a's itsVal\n";
		a = i++;
		std::cout << "Using a.GetItsVal() we see that a's itsVal is " << a.GetItsVal() << std::endl;
        std::cout << "Using i.GetItsVal() we see that i's itsVal was incremented to " << i.GetItsVal() << std::endl;
		return 0;
}
