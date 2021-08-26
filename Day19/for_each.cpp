// Listing 19.12 - STL for_each() algorithm
#include <iostream>
#include <algorithm>
#include <vector>
template<class T>
class Print{
	public:
		void operator()(const T &t) { std::cout << t << " "; }
};
int main(){
	Print<int> DoPrint;
	std::vector<int> vInt(5);
	for(int i=0; i<5; i++)
		vInt[i] = i*3;
	std::cout << "for_each()" << std::endl;
	for_each(vInt.begin(), vInt.end(), DoPrint);
	std::cout << std::endl;
	return 0;
}
