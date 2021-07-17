// Listing 10.13 - Create a new object whose member varialbe is the sum of member values of two objects using a member function
#include <iostream>
class Counter{
        public:
                Counter();
                Counter(int initialValue);                              // non-default constructor
                ~Counter() {}
                int GetItsVal() const { return itsVal; }
                void SetItsVal(int x) { itsVal = x; }
                Counter Add(const Counter&);
        private:
                int itsVal;
};
Counter::Counter():itsVal(0) {}
Counter::Counter(int initialValue):itsVal(initialValue) {}
Counter Counter::Add(const Counter & rhs){
        return Counter(itsVal + rhs.GetItsVal());
}
int main(){
        std::cout << "Declaring and instantiating Counter varOne(2), varTwo(4), and just declaring Counter varThree...\n";
        Counter varOne(2), varTwo(4), varThree;
        varThree = varOne.Add(varTwo);
        std::cout << "Using varThree = varOne.Add(varTwo) we see that varThree's itsVal is " << varThree.GetItsVal() << std::endl;
        return 0;
}
