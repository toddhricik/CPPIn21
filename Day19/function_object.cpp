// Listing 19.11 - Function object
#include <iostream>
template<class T>
class Print{
	public:
		void operator()(const T &t) { std::cout << t << " "; }
};
int main(){
	Print<int> DoPrint;
	for(int i=0; i<5; i++)
		DoPrint(i);
	return 0;
}
