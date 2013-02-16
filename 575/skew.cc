#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	
	string number;
	while (cin >> number) {
		if (atoi(number.c_str()) == 0)	
			return 0;
		unsigned long long outnum = 0;
		for (int index = 0; index < number.size(); ++index) {
			unsigned int digit = number[index] - '0';
			unsigned int curPow = pow(2, number.size() - index) - 1;
			outnum += digit * curPow;
		}
		cout << outnum << endl;
	}
	return 0;
}
