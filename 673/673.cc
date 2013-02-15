#include <cstdlib>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main() {
	unsigned int numCases = 0;
	string asdf;
	getline(cin, asdf);
	numCases = atoi(asdf.c_str());

	for (int kase = 0; kase < numCases; ++kase) {
		string temp;
		getline(cin, temp);
		char sequence[129];
		sequence[129] = '\0';
		strcpy(sequence, temp.c_str());

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
