// Listing 19.2 - Template class implementation of an array
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
// Declare template class of an array
template <class T>
class Array{
	public:
		Array(int itsSize = DefaultSize);
		Array(const Array &rhs);									// copy constructor
		~Array() { delete [] pType; }
		Array& operator=(const Array &rhs);							// should this be Array<T>& operator=(const Array &rhs)????
		T& operator[](int offSet) { return pType[offSet]; }
		const T& operator[](int offSet) const { return pType[offSet]; }
		int GetSize() const { return itsSize; }
	private:
		T *pType;
		int itsSize;
};
// Implement the non-inline template array member functions
template <class T>
Array<T>::Array(int size) : itsSize(size) {
	pType = new T[size];
	// The constructors of the type you are creating should set a default value
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
	if(this==&rhs)
		return *this;
	delete [] pType;
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for(int i=0; i<itsSize; i++)
		pType[i] = rhs[i];
	return *this;
}
int main(){
	Array<int> theArray;											// declares an array of ints
	Array<Animal> theZoo;											// declares an array of Animals
	Animal *pAnimal;
	// Fill in the arrays
	for(int i=0; i<theArray.GetSize(); i++){
		theArray[i] = i*2;
		pAnimal = new Animal(i*3);
		theZoo[i] = *pAnimal;
		delete pAnimal;
	}
	// Print the contents of both arrays
	for(int j=0; j<theArray.GetSize(); j++){
		std::cout << "theArray[" << j << "]:\t";
		std::cout << theArray[j] << "\t\t";
		std::cout << "theZoo[" << j << "]:\t";
		theZoo[j].Display();
		std::cout << std::endl;
	}
	return 0;
}
