#include <iostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

	string line;
	while (getline(cin, line)) {
		int indexOfQuote = 0; 
		bool foundMatch = false;
		while (int indexOfQuote = line.find_first_of("\"") && indexOfQuote != line.npos) {
			if (!foundMatch) {
				line.replace(indexOfQuote,indexOfQuote+1, "``");
			}
			else {
				line.replace(indexOfQuote,indexOfQuote+1, "''");
			}
		}
		cout << line << endl;
	}
}
