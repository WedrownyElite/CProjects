#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <windows.h>
using namespace std;

int main() {

	while (true) {

		int c = 1;
		string userInput;
		string text;

		fstream DBList("DBList.txt", fstream::in | fstream::out | fstream::app);
		cout << "Files:" << endl;
		//Print file names
		while (getline(DBList, text)) {
			cout << text << endl;
			c++;
		}
		cout << endl;
		//User input
		cout << "Which file would you like to open? (TYPE C TO CREATE)" << endl;
		cin >> userInput;

		DBList.close();

		//Create new file
		if (userInput == "C" || userInput == "c") {
			int c = 1;
			string text;
			string userInput;

			system("cls");
			cout << "Files:" << endl;

			fstream DBList("DBList.txt", fstream::in | fstream::out | fstream::app);
			while (getline(DBList, text)) {
				cout << text << endl;
				c++;
			}
			cout << endl;
			DBList.close();
			cout << "Type desired file name:" << endl;
			cin >> userInput;

			//Add .txt to the end of userInput
			string txt = ".txt";
			string fileName1 = userInput + txt;

			//File !exist check
			if (!std::filesystem::exists(fileName1)) {
				//Create the file
				ofstream fileName2(fileName1);
				fileName2.close();

				//Add userInput file name to DBList
				fstream DBList("DBList.txt", ios::app);
				if (DBList.is_open()) {
					DBList << fileName1 << endl;
					DBList.close();
				}
				system("cls");
			}
			//File exists check
			else if (std::filesystem::exists(fileName1)) {
				system("cls");
				cout << "ERROR:0001" << endl << fileName1 << " ALREADY EXISTS!" << endl << endl;
			}

		}
		//Open existing file
		else {

			char userInput1;
			int c = 1;
			string text;
			string txt = ".txt";
			string fullFile = userInput + txt;

			//File found
			if (std::filesystem::exists(fullFile)) {
				fstream fileName(fullFile, fstream::out | fstream::app);
				system("cls");
				cout << fullFile << " has been opened!" << endl;
				cout << endl;
				//Options
				cout << "What would you like to do with " << fullFile << "?" << endl;
				cout << "N : Take notes" << endl;
				cout << "E : General entries" << endl;
				cout << "R : Read from file" << endl;

				cin >> userInput1;
				// Lowercase op
				userInput1 = (char)tolower(userInput1);

				//Note Check
				if (userInput1 == 'n') {
					system("cls");
					cout << "You can start to take notes. When you're done, type 'end'" << endl;

					//Note loop
					while (true) {
						string check = "end";
						string notes;
						string period = ".";
						string space = " ";
						string rawNotes;
						string notes1;

						//UserInput
						std::getline(std::cin, rawNotes);

						//`end` Check
						if (rawNotes == check) {
							fileName.close();
							system("cls");
							break;
						}

						//Period check
						if (rawNotes.length() > 0 && rawNotes[rawNotes.length() - 1] != '.') {
							string notes = rawNotes + period + space;
							fileName << notes;
						}
						else if (rawNotes.length() > 0 && rawNotes[rawNotes.length() - 1] == '.') {
							string notes = rawNotes + space;
							fileName << notes;
						}
					}
				}

				//General Entries
				if (userInput1 == 'e') {
					while (true) {
						string fname;
						string lname;
						string gender;
						string number;
						int num = rand() % 10000;
						std::string id = std::to_string(num);
						system("cls");

						cout << "Type 'end' to leave" << endl << endl;

						// Last name
						cout << "Last name: ";
						cin >> lname;
						//'end' check
						if (lname == "end") {
							system("cls");
							break;
						}
						// First name
						cout << "First name: ";
						cin >> fname;
						//'end' check
						if (fname == "end") {
							system("cls");
							break;
						}
						// Gender
						cout << "Gender: ";
						cin >> gender;
						//'end' check
						if (gender == "end") {
							system("cls");
							break;
						}
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
						//'end' check
						if (number == "end") {
							system("cls");
							break;
						}
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
						char answer;

						// String combination
						string userTCheck = lname + " " + fname + " " + gender + " " + number + " ";
						string userText = lname + "!" + fname + "@" + gender + "#" + number + "$" + id;

						// String confirmation
						cout << userTCheck << endl;
						cout << "Is this correct? (Y/N)" << endl;
						cin >> answer;

						// Answered yes
						if (answer == 'Y') {
							fileName = fstream(fullFile, fstream::out | fstream::app);
							fileName << userText;
							fileName.close();
							cout << "Saved successfully!" << endl;
						}
					}

				}
				//Read from file
				else if (userInput1 == 'r') {
					while (true) {
						string userInput;
						string text;
						int c = 1;

						system("cls");
						cout << "Type 'end' to leave" << endl << endl;
						cout << fullFile << ":" << endl;

						//Print  contents
						fstream fileName(fullFile, fstream::in | fstream::out | fstream::app);
						while (getline(fileName, text)) {
							cout << text << endl;
							c++;
						}
						fileName.close();
						cout << endl;
						cin >> userInput;

						//'end' Check
						if (userInput == "end") {
							system("cls");
							break;
						}
					}
				}
				//Unknown op
				else if (userInput1 != 'r' && userInput1 != 'e' && userInput1 != 'n') {
					system("cls");
					cout << "ERROR:0002" << endl << "Unknown operator" << endl << endl;
				}
			}
			//File not found
			else if (!std::filesystem::exists(fullFile)) {
				system("cls");
				cout << "ERROR:0000 " << endl << fullFile << " Not found!" << endl << endl;
			}
		}

	}
}