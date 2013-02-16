#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

string reverse(string s) {
	string reversedString = "";
	for (int index = s.size()-1; index >= 0; --index) {
		reversedString += s[index];
	}
	return reversedString;
}

bool isPalindrome(string number) {
	for (int index = 0; index < number.size() / 2; ++index) {
		if (number[index] == number[number.size()-1-index])
			continue;
		else
			return false;
	}
	return true;
}

int main() {

	int kases;
	cin >> kases;
	for (int kase = 0; kase < kases; ++kase) {
		string number;
		cin >> number;

		unsigned int iterations = 0;
		do {
			stringstream ss;
			unsigned long long intermediate = atoi(reverse(number).c_str()) + atoi(number.c_str());
			ss << intermediate;
			number = ss.str();
			++iterations;
		} while (!isPalindrome(number) && iterations < 1000);
		cout << iterations << " " << number << endl;
	}

	return 0;
}
