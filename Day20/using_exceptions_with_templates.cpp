// Listing 20.9 - Using exceptions with templates
#include <iostream>
const int DefaultSize = 10;
class xBoundary {};
template<class T>
class Array{
	public:
		Array(int itsSize = DefaultSize);
		Array(const Array &rhs);
		~Array() { delete [] pType; }
		Array& operator=(const Array<T>&);
		T& operator[](int offSet);
		const T& operator[](int offSet) const;
		int GetitsSize() const { return itsSize; }
		friend std::ostream& operator<< (std::ostream&, const Array<T>&);
		// Exception classes
		class xSize {};
	private:
		int itsSize;
		int *pType;
};
template<class T>
Array<T>::Array(int size): itsSize(size) {
	if(size<10 || size > 30000)
		throw xSize();
	pType = new T[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}
template<class T>
Array<T>& Array<T>::operator=(const Array<T> &rhs){
	if(this==&rhs)
		return *this;
	delete [] pType;
	itsSize = rhs.GetitsSize();
	pType = new T[itsSize];
	for(int i=0; i<itsSize; i++)
		pType[i] = rhs[i];
}
template<class T>
Array<T>::Array(const Array<T> &rhs){
	itsSize = rhs.GetitsSize();
	pType = new T[itsSize];
	for(int i=0; i<itsSize; i++)
		pType[i] = rhs[i];
}
template<class T>
T& Array<T>::operator[](int offSet){
	int size = GetitsSize();
	if(offSet>=0 && offSet<GetitsSize())
		return pType[offSet];
	throw xBoundary();
	return pType[0];									// Appease MSC
}
template<class T>
std::ostream& operator<< (std::ostream& output, const Array<T>& theArray){
	for(int i=0; i<theArray.GetitsSize(); i++)
		output << "[" << i << "] " << theArray[i] << std::endl;
	return output;
}
int main(){
	try{
		Array<int> intArray(9);
		for(int j=0; j<100; j++){
			intArray[j] = j;
			std::cout << "intArray[" << j << "] okay...\n";
		}
	}
	catch(xBoundary){
		std::cout << "xBoundary exception. Unable to process your input.\n";
	}
	catch(Array<int>::xSize){
		std::cout << "Array<int>::xSize exception. Bad size.\n";
	}
	std::cout << "Done.\n";
	return 0;
}
