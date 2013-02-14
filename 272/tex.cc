#include <iostream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

int main() {

	string line;
	while (getline(cin, line)) {
		int index = line.find_first_of("\"");
		line.replace(index,index+1, "``");
		cout << line << endl;
	}
}
