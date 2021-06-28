#include <iostream>
int Add(int first, int second)
{
	std::cout << "In Add(), received " << first << " and " << second << "\n";
	return (first + second);
}

int main()
{
	std::cout << "I'm in main()!\n";
	int a, b, c;
	std::cout << "Enter two numbers: ";
	std::cin >> a;
	std::cin >> b;
	std::cout << "\nCalling Add()\n";
	c = Add(a,b);
	std::cout << "\nBack in main().\n";
	std::cout << "c was set to " << c;
	std::cout << "\nExiting...\n\n";
	return 0;
}
