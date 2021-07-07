// Listing 7.15 - Demonstrates solving the nth
// Fibonacci number using iteration

#include <iostream>

unsigned int fib(unsigned int position);
int main()
{
	unsigned int answer, position;
	std::cout << "Which position of the Fibonacci sequence do you want to know?\n";
	std::cin >> position;
	std::cout << "\n";

	answer = fib(position);
	std::cout << answer << " is the Fibonacci sequnce element at postion " << position << "\n";
	return 0;
}

unsigned int fib(unsigned int n){
	unsigned int minusTwo=1, minusOne=1, answer=2;
	if(n<3)
		return 1;

	for(n -= 3; n !=0; n--){
		minusTwo = minusOne;
		minusOne = answer;
		answer = minusOne + minusTwo;
	}

	return answer;
}
