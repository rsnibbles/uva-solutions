#include <iostream>
#include <cstring>
using namespace std;
int main() {
	unsigned int numCases = 0;
	cin >> numCases;

	for (int index = 0; index < numCases; ++index) {
		char sequence[128];
		cin >> sequence;

		char lastMatched = ' ';
		long unmatchedParenthesis = 0;
		long unmatchedBracket = 0;

		for (int i = 0; i < strlen(sequence); ++i) {
			if (sequence[i] == '(') {
				lastMatched = '(';
				++unmatchedParenthesis;
			}
			else if (sequence[i] == ')' && lastMatched == '(') {
				--unmatchedParenthesis;
			}
			else if (sequence[i] == '[') {
				lastMatched = '[';
				++unmatchedBracket;
			}
			else if (sequence[i] == ']' && lastMatched == '[') {
				--unmatchedBracket;
			}
		//cerr << "PARA " << unmatchedParenthesis << endl;
		//cerr << "BRAK " << unmatchedBracket << endl;
		}
		if (unmatchedParenthesis == 0 && unmatchedBracket == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
