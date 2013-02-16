#include <iostream>
#include <sstream>

using namespace std;

int main() {

	int inx,iny;
	cin >> inx >> iny;
	int kase = 1;
	while (inx != 0 && iny != 0) {
		string map[iny];
		for (int line = 0; line < iny; ++line) {
			cin >> map[line];
		}

		char inmap[inx][iny];
		char outmap[inx][iny];
		for (int x = 0; x < inx; ++x) {
			for (int y = 0; y < iny; ++y) {
				inmap[x][y] = map[x][y];
				outmap[x][y] = ' ';
			}
		}

		for (int x = 0; x < inx; ++x) {
			for (int y = 0; y < iny; ++y) {
				int mines = 0;
				if (!(x-1 == -1 || y-1 == -1) && inmap[x-1][y-1] == '*')
					++mines;
				if (!(x-1 == -1) && inmap[x-1][y] == '*')
					++mines;
				if (!(x-1 == -1 || y+1) == iny && inmap[x-1][y+1] == '*')
					++mines;

				if (!(y-1 == -1) && inmap[x][y-1] == '*')
					++mines;
				if (inmap[x][y] == '*')
					outmap[x][y] = '*';
				if (!(y+1 == iny) && inmap[x][y+1] == '*')
					++mines;

				if (!(x+1 == inx || y-1 == -1) && inmap[x+1][y-1] == '*')
					++mines;
				if (!(x+1 == inx) && inmap[x+1][y] == '*')
					++mines;
				if (!(x+1 == inx || y+1 == iny) && inmap[x+1][y+1] == '*')
					++mines;

				if (outmap[x][y] != '*') {
					stringstream ss;
					ss << mines;
					outmap[x][y] = ss.str()[0];
				}
			}
		}

		cout << "Field #" << kase << ":" << endl;
		for (int x = 0; x < inx; ++x) {
			for (int y = 0; y < iny; ++y) {
				cout << outmap[x][y];
			}
			cout << endl;
		}

		++kase;
		cin >> inx >> iny;
	}

	return 0;
}
