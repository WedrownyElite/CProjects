#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string sInput;
		int c = 0;

		cin >> sInput;

		while (sInput[c] != '-' && sInput[c] != '+' && sInput[c] != 'x' && sInput[c] != '*' && sInput[c] != '/') {
			c++;

			if (c == sInput.length()) {
				break;
			}
		}

		int intv;
		int intz;
		if (c != sInput.length()) {
			try {
				intv = stoi(sInput.substr(0, c));
				intz = stoi(sInput.substr(c + 1, sInput.length()));
			}
			catch (invalid_argument ex) {
				cout << "Enter a correct equation: ";
				continue;

			}
		}
			switch (sInput[c]) {
			case '+':
				cout << intv + intz << "\n";
				break;
			case '-':
				cout << intv - intz << "\n";
				break;
			case '*':
			case 'x':
				cout << intv * intz << "\n";
				break;
			case '/':
				cout << intv / intz << "\n";
				break;
			}
	}
}
