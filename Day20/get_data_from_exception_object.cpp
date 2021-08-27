// Listing 20.7 - getting data from an exception object
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
		// Exception classes
		class xBoundary {};
		class xSize{
			public:
				xSize(int size) : itsSize(size) {}
				~xSize() {}
				int GetSize() { return itsSize; }
			private:
				int itsSize;
		};
		class xTooBig : public xSize {
			public:
				xTooBig(int size) : xSize(size) {}
		};
		class xTooSmall : public xSize {
			public:
				xTooSmall(int size) : xSize(size) {}
		};
		class xZero : public xTooSmall {
			public:
				xZero(int size) : xTooSmall(size) {}
		};
		class xNegative : public xSize {
			public:
				xNegative(int size) : xSize(size) {}
		};
	private:
		int *pType;
		int itsSize;
};
Array::Array(int size) : itsSize(size) {
	if(size==0)
		throw xZero(size);
	if(size>30000)
		throw xTooBig(size);
	if(size<1)
		throw xNegative(size);
	if(size<10)
		throw xTooSmall(size);
	pType = new int[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}
int& Array::operator[](int offSet) {
	int size = GetitsSize();
	if(offSet>=0 && offSet<size)
		return pType[offSet];
	throw xBoundary();
	return pType[0];								// Appease MSC
}
const int& Array::operator[](int offSet) const {
	int size = GetitsSize();
	if(offSet>=0 && offSet<size)
		return pType[offSet];
	throw xBoundary();
	return pType[0];								// Appease MSC
}
int main(){
	try{
		Array intArray(9);
		for(int j=0; j<100; j++){
			intArray[j] = j;
			std::cout << "intArray[" << j<< "] okay..\n";
		}
	}
	catch(Array::xBoundary){
		std::cout << "xBoundary exeption. Unable to process your input.\n";
	}
	catch(Array::xZero theException){
		std::cout << "xZero exception. You asked for an array of zero objects.\n";
		std::cout << "Received " << theException.GetSize() << " objects.\n";
	}
	catch(Array::xTooBig theException){
		std::cout << "xTooBig exception. This array is too big...\n";
		std::cout << "Recieved " << theException.GetSize() << " objects.\n";
	}
	catch(Array::xTooSmall theException){
		std::cout << "xTooSmall exception. This array is too small...\n";
		std::cout << "Received " << theException.GetSize() << " objects.\n";
	}
	catch(...){
		std::cout << "Something else went wrong which was caught by the (...) handler.\n";
	}
	std::cout << "Done.\n";
	return 0;
}


	
