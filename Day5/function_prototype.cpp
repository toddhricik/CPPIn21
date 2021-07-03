/* Listing 5.1 - deomonstrates the use of fucntion prototypes */

#include <iostream>
int Area(int length, int width); 	// function declaration

int main()
{
	using std::cout;
	using std::cin;

	int lengthOfYard;
	int widthOfYard;
	int areaOfYard;

	cout << "\nHow wide is your yard? ";
	cin >> widthOfYard;
	cout << "\nHow long is your yard? ";
	cin >> lengthOfYard;

	areaOfYard = Area(lengthOfYard, widthOfYard);

	cout << "\nYour yard is ";
	cout << areaOfYard;
	cout << " square feet\n\n";
	return 0;
}

int Area(int len, int wid)
{
	return len * wid;
}

