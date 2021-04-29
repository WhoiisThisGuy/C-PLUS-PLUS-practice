/* Simple calculator that understands 4 basic aritmethic operator: +,-,/,* 
   No error handling. */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int GetANumber(string& inputstr) {

	unsigned int idx{ 0 };
	float number = std::stoi(inputstr, &idx);
	inputstr = inputstr.substr(idx, string::npos);
	return number;
}

char GetAnOperator(string& inputstr) {
	if (!inputstr.length()) {
		return '\0';
	}
	unsigned int idx{ 1 };
	char c = inputstr.at(0);
	inputstr = inputstr.substr(idx, string::npos);
	return c;
}

int main() {

	char op{ '\0' };
	float num{ 0 };
	string inputstr{ "" };
	queue<float> numbers;
	cout << "Enter a matemathical expression (without parenthesis): " << '\n';
	cin >> inputstr;

	if (inputstr == "")
		return 0;

	num = GetANumber(inputstr);
	numbers.push(num);

	while (inputstr.length()) {

		op = GetAnOperator(inputstr);

		{
			int prevNum{ 0 };
			switch (op) {
			case '+':
				num = GetANumber(inputstr);
				numbers.push(num);
				break;
			case '-':
				num = GetANumber(inputstr);
				numbers.push(-num);
				break;
			case '*':
				num = GetANumber(inputstr);
				prevNum = numbers.front();
				numbers.pop();
				numbers.push(prevNum * num);
				break;
			case '/':
				num = GetANumber(inputstr);
				prevNum = numbers.front();
				numbers.pop();
				numbers.push(prevNum / num);
				break;
			case '\0':
				numbers.push(num);
				break;
			}
		}
	}

	int result{0};

	while (!numbers.empty()) {
		result += numbers.front();
		numbers.pop();
	}

	cout << "The result is: " << result << '\n';

	return 0;
}
