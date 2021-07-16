// Listing 10.11 - Overload prefix ++ operator using this pointer instead of temporary object
#include <iostream>
class Counter{
	public:
		Counter();
		~Counter() {}
		int GetItsVal() const { return itsVal; }
		void SetItsVal(int x) { itsVal = x; }
		void Increment() { ++itsVal; }
		const Counter& operator++ ();
	private:
		int itsVal;
};
Counter::Counter():itsVal(0) {}
const Counter & Counter::operator++(){
	++itsVal;
	return *this;
}
int main(){
        std::cout << "Declaring and instantiating Counter i using the default initializer for itsVal in the constructor...\n";
        Counter i;
        std::cout << "Using i.GetItsVal() to see that i's itsval is " << i.GetItsVal() << std::endl;
        std::cout << "Using i.Increment() to increment i's itsval...\n";
        i.Increment();
        std::cout << "Using i.GetItsVal() we see i's itsval is now " << i.GetItsVal() << std::endl;
        std::cout << "Using ++i to increment i's itsVal using the overloaded ++ prefix operator...\n";
        ++i;
        std::cout << "Using i.GetItsVal() we see that i's itsVal is now " << i.GetItsVal() << std::endl;
        std::cout << "Declaring a new Counter \"a\" and intantiating it to ++i using the default copy constructor...\n";
        Counter a = ++i;
        std::cout << "Using a.GetItsVal() we see that a's itsVal is " << a.GetItsVal() << std::endl;
        std::cout << "Using i.GetItsVal() we see that i's itsVal was incremented to " << i.GetItsVal() << std::endl;
	std::cout << "i is at address " << (long) &i << std::endl;
	std::cout << "a is at address " << (long) &a << std::endl;
	return 0;
}
