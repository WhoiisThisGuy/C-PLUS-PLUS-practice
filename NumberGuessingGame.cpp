//Number guessing game
//The user enters a number that he tought about.
//The computer tries to guess by askin questions.
//Questions like: Is it less than 50?
//The user answers by y or n to the question.

#include <iostream>

using namespace std;

void binaryGuess(const int max) {
	int left{ 0 }, right{ max };
	while (left <= right) {
		char answer{ 'n' };
		int mid = (left + right) / 2;
		cout << "Is your number LESS than: " << mid << "?(y/n)\n";
		cin >> answer;
		if (answer == 'y') {
			right = mid - 1;
			continue;
		}
		cout << "Is your number GREATER than: " << mid << "?(y/n)\n";
		cin >> answer;
		if (answer == 'y') {
			left = mid + 1;
			continue;
		}
		else {
			cout << "You guessed the number: " << mid << '\n';
			return;
		}
	}
	cout << "I have no idea what number you guessed but\nI think you lied to me in one of your questions.\n";
	return;
}

int main()
{
	
	const int maxGuess{100}; //Guess a number between 0 and maxguess

	cout << "Think a number betwwen 0 - " << maxGuess << " and I will guess which number was it. Ready?(y/n)\n";
	getchar();

	binaryGuess(maxGuess);
}