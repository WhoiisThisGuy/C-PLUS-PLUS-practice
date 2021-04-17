#include <iostream>
#include <vector>

//Bulls and cows game
//Stop the game with invalid inputs, for example enter a character.
//No error handling added for wrong inputs.

/* The program has a vector of four integers in the range 0 to 9
and it is the user's task to discover those numbers_vector by repeated guesses.
Say the number to be guessed is 1234 and the user guesses 1359; the response
should be " 1 bull and 1 cow" because the user got one digit(1)
right and in the right position(a bull) and one digit(3) right but in the
wrong position(a cow).The guessing continues until the user gets four
bulls, that is, has the four digits correct and in the correct order.
~ Bjarne Stroustroup - Programming Principles and Practice using C++ */

using namespace std;

bool isBull(const int& input, const int& index);
bool isCow(const vector<int>& numbers_vector, const int& input);
bool isAllBull(const vector<int>& numbers_vector, const vector<int>& inputs_vector);
bool Userinputs(vector<int>& inputs_vector);

int main() {

	const vector<int>numbers_vector = { 1,2,3,4 };
	vector<int> inputs_vector(numbers_vector.size());

	std::fill(inputs_vector.begin(), inputs_vector.end(), 0);

	bool gameOver = false;

	cout << "Bulls and cows game.\nType one number at a time and then press enter.\n";

	while (!gameOver) {
		if (!Userinputs(inputs_vector)) break;
		if (isAllBull(numbers_vector, inputs_vector)) { cout << "You won!\n"; gameOver = true; };
	}

	return 0;
}

bool isAllBull(const vector<int>& numbers_vector, const vector<int>& inputs_vector) { //gives true if all is bulls, false else

	unsigned int bulls{ 0 }, cows{ 0 };

	for (unsigned int i = 0; i < inputs_vector.size(); ++i) {
		if (isBull(inputs_vector[i], numbers_vector[i])) {
			++bulls;
			continue;
		}
		else if (isCow(numbers_vector, inputs_vector[i])) {
			++cows;
			continue;
		}
	}
	cout << '\n' << bulls << " bulls and " << cows << " cows\n";
	return bulls == numbers_vector.size();
}

bool isBull(const int& input, const int& number) {
	return input == number;
}

bool isCow(const vector<int>& numbers_vector, const int& input) {
	return std::find(numbers_vector.begin(), numbers_vector.end(), input) != numbers_vector.end();
}

bool Userinputs(vector<int>& inputs) {
	cout << "\Enter the " << inputs.size() << " numbers, one at a time:\n";
	for (auto& i : inputs) if (!(cin >> i)) return false;
	return true;
}