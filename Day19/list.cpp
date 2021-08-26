// Liting 19.9 - STL list and iterator
#include <iostream>
#include <list>
typedef std::list<int> IntegerList;
int main(){
	IntegerList intList;
	for(int i=1; i<=10; i++)
		intList.push_back(i*2);
	for(IntegerList::const_iterator ci=intList.begin(); ci != intList.end(); ++ci)
		std::cout << *ci << " ";
	return 0;
}
