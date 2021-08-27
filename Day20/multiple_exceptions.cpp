// Listing 20.5 - Multiple exceptions
#include <iostream>
const int DefaultSize = 10;
class Array{
	public:
		Array(int itsSize = DefaultSize);
		Array(const Array &rhs);
		~Array() { delete [] pType; }
		Array& operator=(const Array&);
		int& operator[](int offSet);
		const int& operator[](int offSet) const;
		int GetitsSize() const { return itsSize; }
		friend std::ostream& operator<< (std::ostream&, const Array&);
		// exception classees
		class xBoundary {};
		class xTooBig {};
		class xTooSmall {};
		class xZero {};
		class xNegative {};
	private:
		int *pType;
		int itsSize;
};
int& Array::operator[](int offSet){
	int size = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];															// Appease MSC
}
const int& Array::operator[](int offSet) const{
	int mysize = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];															// Appease MSC
}
Array::Array(int size) : itsSize(size) {
	if(size==0)
		throw xZero();
	if(size<10)
		throw xTooSmall();
	if(size>30000)
		throw xTooBig();
	if(size<1)
		throw xNegative();
	pType = new int[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}
int main(){
	try{
		Array intArray(0);
		for(int j=0; j<100; j++){
			intArray[j] = j;
			std::cout << "intArray[" << j << "] okay...\n";
		}
	}
	catch(Array::xBoundary){
		std::cout << "Unable to process input. xBoundary() exception.\n";
	}
	catch(Array::xTooBig){
		std::cout << "This array is too big...\n";
	}
	catch(Array::xTooSmall){
		std::cout << "This array is too small...\n";
	}
	catch(Array::xZero){
		std::cout << "You asked for an array of zero objects.\n";
	}
	catch(...){
		std::cout << "Something went wrong.\n";
	}
	std::cout << "Done.\n";
	return 0;
}
