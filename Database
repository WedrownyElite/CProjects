#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {

	char op;
	string fname;
	string lname;
	string gender;
	string number;
	string id;

	// Get op
	cout << "Edit (E), or write? (W) ";
	cin >> op;

	// Lowercase op
	op = (char)tolower(op);

	// Op check
	while (op != 'w' && op != 'e' && op) {
		cout << "Unknown. Edit, or write? ";
		cin >> op;
	}

	// Write
	if (op == 'w') {
		// Last name
		cout << "Last name: ";
		cin >> lname;
		// First name
		cout << "First name: ";
		cin >> fname;
		// Gender
		cout << "Gender: ";
		cin >> gender;
		// Gender Check
		while (gender != "Female" && gender != "F" && gender != "Male" && gender != "M") {
			cout << "Unknown. Gender: ";
			cin >> gender;
		}
		if (gender == "Male" || gender == "M") {
			gender = "M";
		}
		else if (gender == "Female" || gender == "F") {
			gender = "F";
		}
		// Phone number
		cout << "Phone number: ";
		cin >> number;
		// Phone number check
		while (number.length() > 10) {
			cout << "Too many digits" << endl;
			cout << "Phone number: ";
			cin >> number;
		}
		while (number.length() < 10) {
			cout << "Not enough digits" << endl;
			cout << "Phone number: ";
			cin >> number;
		}

		// File entries

		// Open Database
		fstream Database("Database.txt", ios::app);
		if (Database.is_open()) {
			// Last name
			Database << lname << "!";
			// First name
			Database << fname << "@";
			// Gender
			Database << gender << "#";
			// Phone number
			Database << number << "$" << endl;

			Database.close();
		}
	}

	// Edit
	while (true) {
	if (op == 'e') {

		string text;
		int c = 1;
		fstream Database("Database.txt", fstream::in | fstream::out | fstream::app);
		while (getline(Database, text)) {
			cout << c << ": ";
			cout << text << endl;
			c++;
		}
		Database.close();

		// Rewriting
		int lineNumber;
		string lname;
		string fname;
		string gender;
		string number;
		string line;
		vector<string> lines;
		char answer;

			// User input
			// Line
			cout << "Line: ";
			cin >> lineNumber;
			// Last name
			cout << "Last name: ";
			cin >> lname;
			// First name
			cout << "First name: ";
			cin >> fname;
			// Gender
			cout << "Gender: ";
			cin >> gender;
			// Gender Check
			while (gender != "Female" && gender != "F" && gender != "Male" && gender != "M") {
				cout << "Unknown. Gender: ";
				cin >> gender;
			}
			if (gender == "Male" || gender == "M") {
				gender = "M";
			}
			else if (gender == "Female" || gender == "Male") {
				gender = "F";
			}
			// Phone number
			cout << "Phone number: ";
			cin >> number;
			// Phone number check
			while (number.length() > 10) {
				cout << "Too many digits" << endl;
				cout << "Phone number: ";
				cin >> number;
			}
			while (number.length() < 10) {
				cout << "Not enough digits" << endl;
				cout << "Phone number: ";
				cin >> number;
			}

			// String combination
			string userTCheck = lname + " " + fname + " " + gender + " " + number + " ";
			string userText = lname + "!" + fname + "@" + gender + "#" + number + "$";

			// String confirmation
			cout << userTCheck << endl;
			cout << "Is this correct? (Y/N)" << endl;
			cin >> answer;

			// Answered yes
			if (answer == 'Y') {
				// Add lines from Database to vector
				Database = fstream("Database.txt", fstream::in);
				while (getline(Database, line)) {
					lines.push_back(line);
				}
				Database.close();

				// Switch user defined line number
				Database = fstream("Database.txt", fstream::trunc);
				lineNumber--;
				lines[lineNumber] = userText;

				// Overwrite Database file with vector
				for (std::string& line : lines) {
					Database << line << endl;
				}
				// Rewrite done. YAY!
				Database.close();
				cout << "Rewrite Successful";
				break;
			}
		}
	}

}
