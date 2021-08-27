// Listing 20.6 - Class hierachies and exceptions
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
		// Exeption classes
		class xBoundary {};
		class xSize{};
		class xTooBig : public xSize {};
		class xTooSmall : public xSize {};
		class xZero : public xTooSmall {};
		class xNegative : public xSize {};
	private:
		int *pType;
		int itsSize;
};
Array::Array(int size) : itsSize(size) {
	if(size==0)
		throw xZero();
	if(size>30000)
		throw xTooBig();
	if(size<1)
		throw xNegative();
	if(size<10)
		throw xTooSmall();
	pType = new int[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}
int& Array::operator[](int offSet){
	int size = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];													// Appease MSC
}
const int& Array::operator[](int offSet) const{
	int mysize = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];													// Appease MSC
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
		std::cout << "xBoundary excetpion. Unable to process your input.\n";
	}
	catch(Array::xTooBig){
		std::cout << "xTooBig exception. This array is too big...\n";
	}
	catch(Array::xTooSmall){
		std::cout << "xTooSmall exception. This array is too small...\n";
	}
	catch(Array::xZero){
		std::cout << "xZero exception. You asked for an array of zero objects...\n";
	}
	catch(...){
		std::cout << "Something went wrong and was caught by the (...) handler...\n";
	}
	std::cout << "Done.\n";
	return 0;
}
