// Listing 21.1 - using #define #ifdef #ifndef #else #endif precompiler commands
#define DemoVersion
#define SW_VERSION 5
#include <iostream>
int main(){
	std::cout << "Checking ont he definitions of DemoVersion,";
	std::cout << "SW_VERSION, and WINDOWS_VERSTION...\n";
	#ifdef DemoVersion
		std::cout << "DemoVersion defined.\n";
	#else
		std::cout << "DemoVersion not defined.\n";
	#endif
	#ifndef SW_VERSION
		std::cout << "SW_VERSION not defined.\n";
	#else
		std::cout << "SW_VERSION defined as " << SW_VERSION << ".\n";
	#endif
	#ifdef WINDOWS_VERSION
		std::cout << "WINDOWS_VERSION defined.\n";
	#else
		std::cout << "WINDOWS_VERSION not defined.\n";
	#endif
	std::cout << "Done.\n";
	return 0;
}
