#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	unsigned int numCases = 0;
	cin >> numCases;

	for (int index = 0; index < numCases; ++index) {
		char sequence[128];
		cin >> sequence;

		vector<char> paraStack;	
		long unmatchedParenthesis = 0;
		long unmatchedBracket = 0;

		for (int i = 0; i < strlen(sequence); ++i) {
			if (sequence[i] == '(') {
				paraStack.push_back('(');
				++unmatchedParenthesis;
			}
			else if (sequence[i] == ')') {
				if (paraStack.back() == '(')
					paraStack.pop_back();
				--unmatchedParenthesis;
			}
			else if (sequence[i] == '[') {
				paraStack.push_back('[');
				++unmatchedBracket;
			}
			else if (sequence[i] == ']') {
				if (paraStack.back() == '[')
					paraStack.pop_back();
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
