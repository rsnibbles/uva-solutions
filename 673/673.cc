#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main() {
	unsigned int numCases = 0;
	cin >> numCases;

	for (int index = 0; index < numCases; ++index) {
		char sequence[128];
		cin >> sequence;

		stack<char> paraStack;

		bool fail = false;
		for (int index = 0; index < strlen(sequence); ++index) {
			if (sequence[index] == '(') {
				paraStack.push('(');
			}
			else if (sequence[index] == '[') {
				paraStack.push('[');
			}
			else if (sequence[index] == ')') {
				if (!paraStack.empty() && paraStack.top() == '(')
					paraStack.pop();
				else
					fail = true;
			}
			else if (sequence[index] == ']') {
				if (!paraStack.empty() && paraStack.top() == '[')
					paraStack.pop();
				else
					fail = true;
			}
			if (fail)
				break;
		}

		if (paraStack.empty() && !fail)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
