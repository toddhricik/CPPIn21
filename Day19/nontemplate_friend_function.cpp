// Listing 19.3 - Non-template friend function
#include <iostream>
const int DefaultSize = 10;
class Animal{
	public:
		Animal(int);
		Animal();
		~Animal() {}
		int GetWeight() const { return itsWeight; }
		void Display() const { std::cout << itsWeight; }
	private:
		int itsWeight;
};
Animal::Animal(int weight) : itsWeight(weight) {}
Animal::Animal() : itsWeight(0) {}
template <class T>												// decalre the template and th parameter 
class Array{
	public:
		Array(int itsSize = DefaultSize);
		Array(const Array &rhs);
		~Array() { delete [] pType; }
		Array& operator=(const Array &rhs);
		T& operator[](int offSet) { return pType[offSet]; }
		const T& operator[](int offSet) const { return pType[offSet]; }
		int GetSize() const { return itsSize; }
		friend void Intrude(Array<int>);
	private:
		T *pType;
		int itsSize;
};
// This friend function is not a template, therefore can only be used
// with int arrays.
void Intrude(Array<int> theArray){
	std::cout << std::endl << "*** Intrude ***" << std::endl;
	for(int i=0; i<theArray.itsSize; i++)
		std::cout << "i: " << theArray.pType[i] << std::endl;
	std::cout << std::endl;
}
template <class T>
Array<T>::Array(int size) : itsSize(size) {
	pType = new T[size];
	// The constructors of the type you are creating should set to a default value
}
template <class T>
Array<T>::Array(const Array &rhs){
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for(int i=0; i<itsSize; i++)
		pType[i] = rhs[i];
}
template <class T>
Array<T>& Array<T>::operator=(const Array &rhs){
	if(this == &rhs)
		return *this;
	delete [] pType;
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for(int i=0; i<itsSize; i++)
		pType[i] = rhs[i];
	return *this;
}
int main(){
	Array<int> theArray;										// Declare an array of ints
	Array<Animal> theZoo;										// Declare an array of Animals
	Animal *pAnimal;
	// fill the arrays
	for(int i=0; i<theArray.GetSize(); i++){
		theArray[i] = i*2;
		pAnimal = new Animal(i*3);
		theZoo[i] = *pAnimal;
	}
	int j;
	for(j=0; j<theArray.GetSize(); j++){
		std::cout << "theZoo[" << j << "]:\t";
		theZoo[j].Display();
		std::cout << std::endl;
	}
	std::cout << "Now using the friend function to find the members of Array<int>";
	Intrude(theArray);
	std::cout << std::endl;
	return 0;
}
