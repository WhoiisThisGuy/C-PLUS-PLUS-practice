#include <iostream>
#include <vector>

//Bulls and cows game
//Stop the game with invalid inputs, for example enter a character.
//No error handling added for wrong inputs.

/* The program has a vector of four integers in the range 0 to 9
and it is the user's task to discover those numbers by repeated guesses.
Say the number to be guessed is 1234 and the user guesses 1359; the response
should be " 1 bull and 1 cow" because the user got one digit(1)
right and in the right position(a bull) and one digit(3) right but in the
wrong position(a cow).The guessing continues until the user gets four
bulls, that is, has the four digits correct and in the correct order.
~ Bjarne Stroustroup - Programming Principles and Practice using C++ */

using namespace std;

bool isBull(const int& input, const int& index);
bool isCow(const vector<int>& numbers, const int& input);
bool isAllBull(const vector<int>& numbers, const vector<int>& inputs);
bool Userinputs(vector<int>& inputs);

int main() {

	const vector<int>numbers = { 1,2,3,4 };
	vector<int> inputs(numbers.size());

	std::fill(inputs.begin(), inputs.end(), 0);

	bool gameOver = false;

	cout << "Bulls and cows game.\nType one number at a time and then press enter.\n";

	while (!gameOver) {
		if (!Userinputs(inputs)) break;
		if (isAllBull(numbers, inputs)) { cout << "You won!\n"; gameOver = true; };
	}

	return 0;
}

bool isAllBull(const vector<int>& numbers, const vector<int>& inputs) { //gives true if all is bulls, false else

	unsigned int bulls{ 0 }, cows{ 0 };

	for (unsigned int i = 0; i < inputs.size(); ++i) {
		if (isBull(inputs[i], numbers[i])) {
			++bulls;
			continue;
		}
		else if (isCow(numbers,inputs[i])) {
			++cows;
			continue;
		}
	}
	cout << '\n' << bulls << " bulls and " << cows << " cows\n";
	return bulls == numbers.size();
}

bool isBull(const int& input, const int& number) {
	return input == number;
}

bool isCow(const vector<int>& numbers, const int& input) {
	return std::find(numbers.begin(), numbers.end(), input) != numbers.end();
}

bool Userinputs(vector<int>& inputs) {
	cout << "\Enter the " << inputs.size() << " numbers, one at a time:\n";
	for (auto& i : inputs) if (!(cin >> i)) return false;
	return true;
}