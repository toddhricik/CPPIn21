// Listing 19.13 - STL fill() algorithm
#include <iostream>
#include <vector>
#include <algorithm>
template<class T>
class Print{
	public:
		void operator()(const T &t){ std::cout << t << " "; }
};
int main(){
	Print<int> DoPrint;
	std::vector<int> vInt(10);
	fill(vInt.begin(), vInt.begin()+5, 1);
	fill(vInt.begin()+5, vInt.end(), 2);
	for_each(vInt.begin(), vInt.end(), DoPrint);
	std::cout << std::endl;
	return 0;
}
