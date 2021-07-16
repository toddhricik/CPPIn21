// Listing 10.10 - using prefix operator ++ and returning a nameless temporary object
#include <iostream>
class Counter{
	public:
		Counter();
		Counter(int val);
		~Counter() {}
		int GetItsVal() const { return itsVal; }
		void SetItsVal(int x) { itsVal = x; }
		void Increment() { ++itsVal; }
		Counter operator++ ();
	private:
		int itsVal;
};
Counter::Counter():itsVal(0){}
Counter::Counter(int val):itsVal(val){}
Counter Counter::operator++(){
	++itsVal;
	return Counter(itsVal);
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
        return 0;
}
