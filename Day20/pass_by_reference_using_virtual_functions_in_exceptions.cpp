// Listing 20.8 - Passing by reference and using virtual functions in exceptions
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
				virtual int GetSize() { return itsSize; }
				virtual void PrintError() {
					std::cout << "Size error. Received ";
					std::cout << itsSize << " objects.\n";
				}
			protected:
				int itsSize;
		};
		class xTooBig : public xSize {
			public:
				xTooBig(int size) : xSize(size) {}
				virtual void PrintError(){
					std::cout << "Too big. Received ";
					std::cout << xSize::itsSize << " objects.\n";
				}
		};
		class xTooSmall : public xSize {
			public:
				xTooSmall(int size) : xSize(size) {}
				virtual void PrintError(){
					std::cout << "Too small. Received ";
					std::cout << xSize::itsSize << " objects.\n";
				}
		};
		class xZero : public xTooSmall {
			public:
				xZero(int size) : xTooSmall(size) {}
				virtual void PrintError(){
					std::cout << "Zero. Received ";
					std::cout << xSize::itsSize << " objects.\n";
				}
		};
		class xNegative : public xSize {
			public:
				xNegative(int size) : xSize(size) {}
				virtual void PrintError(){
					std::cout << "Negative. Received ";
					std::cout << xSize::itsSize << " objects.\n";
				}
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
	if(size<0)
		throw xNegative(size);
	if(size<10)
		throw xTooSmall(size);
	pType = new int[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}
int& Array::operator[](int offSet){
	int size = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];										// Appease MSC
}
const int& Array::operator[](int offSet) const {
	int size = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];										// Appease MSC
}
int main(){
	try{
		Array intArray(9);
		for(int j=0; j<100; j++){
			intArray[j] = j;
			std::cout << "intArray[" << j << "] okay...\n";
		}
	}
	catch(Array::xBoundary){
		std::cout << "xBoundary exception. Unable to process your input.\n";
	}
	catch(Array::xSize& theException){
		theException.PrintError();
	}
	catch(...){
		std::cout << "Something went wrong that was caught by the (...) handler.\n";
	}
	std::cout << "Done.\n";
	return 0;
}
