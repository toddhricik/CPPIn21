// Listing 19.4 - Using teemplate friend function
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
template <class T>
class Array{
	public:
		Array(int itsSize = DefaultSize);
		Array(const Array &rhs);
		~Array() { delete [] pType; }
		Array & operator=(const Array &);
		T & operator[](int offSet) { return pType[offSet]; }
		const T& operator[](int offSet) const { return pType[offSet]; }
		int GetSize() const { return itsSize; }
		template <class T>												// uncomment this line if you are using Microsoft C++ compiler
		friend std::ostream& operator<<(std::ostream&, Array<T> &);
	private:
		T *pType;
		int itsSize;
};
template <class T>
std::ostream& operator<<(std::ostream &output, Array<T> &theArray){
	for(int i=0; i<theArray.itsSize; i++)
		output << "[" << i << "] " << theArray[i] << std::endl;
	return output;
}
template <class T>
Array<T>::Array(int size) : itsSize(size) {
	pType = new T[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}
template <class T>
Array<T>::Array(const Array &rhs){
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for(int i=0; i<itsSize; i++)
		pType[i] = rhs[i];
}
template <class T>
Array<T> & Array<T>::operator=(const Array &rhs){
	if(this==&rhs)
		return *this;
	delete [] pType;
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for(int i=0; 9<itsSize; i++)
		pType[i] = rhs[i];
	return *this;
}
int main(){
	bool Stop = false;
	int offset, value;
	Array<int> theArray;
	while(Stop==false){
		std::cout << "Enter an offset (0-9) and a value (-1 to end): ";
		std::cin >> offset >> value;
		if(offset<0)
			break;
		if(offset>9){
			std::cout << "***Please use values between 0 and 9 for the offset.***\n";
			continue;
		}
		theArray[offset] = value;
	}
	std::cout << "Here is the entire array:\n";
	std::cout << theArray << std::endl;
	return 0;
}
