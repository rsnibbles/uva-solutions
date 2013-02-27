#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	map<string,string> wordMap;
	string word;
	cin >> word;
	while (word != "#") {
		if (word.size() < 2) {
			cin >> word;
			continue;
		}
		string key = word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		sort(word.begin(), word.end());
		wordMap[key] = word;
		cin >> word;
	}

	for (map<string,string>::iterator it = wordMap.begin(); it != wordMap.end(); ++it) {
		bool foundMatch = false;
		for (map<string,string>::iterator it2 = wordMap.begin(); it2 != wordMap.end(); ++it2) {
			if (it == it2)
				continue;
			//cerr << "COMP: " << it->second << " " << it2->second << endl;
			if (it->second == it2->second) {
				//cerr << "Matched: " << it->second << " " << it2->second << endl;
				foundMatch = true;
				wordMap.erase(it2);
			}
		}
		if (foundMatch)
			wordMap.erase(it);
	}

	for (map<string,string>::iterator it = wordMap.begin(); it != wordMap.end(); ++it) {
		cout << it->first << endl;
	}
}
