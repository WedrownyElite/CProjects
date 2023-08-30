	#include <iostream>
	#include <fstream>
	#include <string>
	#include <filesystem>
	using namespace std;
	//IMPLEMENT VARIABLE FILESYSTEM::PATH, START Filesystem::path p = filesystem::current_path() / userInput; AFTER EACH USER INPUT.
	//CHECK TEST
	int printFileNames() {
		const filesystem::path f{"files"};
		filesystem::path p = filesystem::current_path();
		if (!filesystem::is_directory(p / "files")) {
			create_directories(f);
			cout << "'files' folder created at " << (p / "files").string() << endl << endl;
		}
		else if (filesystem::is_directory(p / "files")) {
			cout << "Files:" << endl;
			for (const auto& entry : filesystem::directory_iterator(f)) {
				if (entry.is_regular_file()) {
					cout << entry.path().filename() << endl;
				}
			}
			cout << endl << "Folders:" << endl;
			for (const auto& entry : filesystem::directory_iterator(f)) {
				if (entry.is_directory()) {
					cout << entry.path().filename() << endl;
				}
			}
		}
		cout << endl;
		return 0;
	}

	int printFileNamesSubFolder(string openUserInput) {
		const filesystem::path f{"files"};
		filesystem::path p = filesystem::current_path();
		if (!filesystem::is_directory(p / "files" / openUserInput)) {
			create_directories(f);
			cout << "'files' folder created at " << (p / "files").string() << endl << endl;
		}
		else if (filesystem::is_directory(p / "files" / openUserInput)) {
			cout << "Files:" << endl;
			for (const auto& entry : filesystem::directory_iterator(f)) {
				if (entry.is_regular_file()) {
					cout << entry.path().filename() << endl;
				}
			}
			cout << endl << "Folders:" << endl;
			for (const auto& entry : filesystem::directory_iterator(f)) {
				if (entry.is_directory()) {
					cout << entry.path().filename() << endl;
				}
			}
		}
		cout << endl;
		return 0;
	}

	int fileNotFound(string fullFile) {
		system("cls");
		cout << "ERROR:0000 " << endl << fullFile << " Not found!" << endl << endl;
		return 1;
	}

	int options(string fullFile) {
		char userInput1;

		cout << "What would you like to do with " << fullFile << "?" << endl;
		cout << "N : Take notes" << endl;
		cout << "E : General entries" << endl;
		cout << "R : Read from file" << endl;
		cout << "D : Delete file" << endl;
		cout << "B : Go back" << endl;

		cin >> userInput1;
		// Lowercase op
		userInput1 = (char)tolower(userInput1);

		return(userInput1);
	}

	int uCharCheck(string openUserInput) {
		const char uchar[] = { '<', '#', '>', '$', '+', '%', '!', '`', '&', '*', '\'', '"', '|', '{', '}', '?', '=', '/', '\\', ':', ' ', '@' };
		for (int a = 0; openUserInput[a] != '\0'; a++) {
			for (int d = 0; d < 21; d++) {
				if (openUserInput[a] == uchar[d]) {
					system("cls");
					cout << '\'' << openUserInput << '\'' << " contains an illegal character: " << uchar[d] << endl << endl;
					return 1;
				}
			}
		}
		return 0;
	}

	int uCharCheckFolder(string folderUserInput) {
		const char uchar[] = { '<', '#', '>', '$', '+', '%', '!', '`', '&', '*', '\'', '"', '|', '{', '}', '?', '=', '/', '\\', ':', ' ', '@' };
		for (int a = 0; folderUserInput[a] != '\0'; a++) {
			for (int d = 0; d < 21; d++) {
				if (folderUserInput[a] == uchar[d]) {
					system("cls");
					cout << '\'' << folderUserInput << '\'' << " contains an illegal character: " << uchar[d] << endl << endl;
					return 1;
				}
			}
		}
		return 0;
	}

	int dirPath(string fullFile, filesystem::path files) {
		system("cls");
		cout << files << " > " << fullFile << endl << endl;
		return 0;
	}

	int dirPathBack(filesystem::path files) {
		system("cls");
		cout << files << endl << endl;
		return 0;
	}

	int dirPathOp(string fullFile, char userInput1, filesystem::path files) {

		system("cls");
		//Note path
		if (userInput1 == 'n') {
			cout << files << " > " << fullFile << " > " << "Notes" << endl << endl;
		}
		else if (userInput1 == 'e') {
			cout << files << " > " << fullFile << " > " << "Entries" << endl << endl;
		}
		else if (userInput1 == 'r') {
			cout << files << " > " << fullFile << " > " << "Read" << endl << endl;
		}
		else {
			cout << files << endl << endl;
		}
		return 0;
	}

	int dirPathCreate() {
		const filesystem::path files{"files"};
		system("cls");
		cout << files << " > " << "Create" << endl << endl;
		return 0;
	}

	int dirPathSubFolder(string openUserInput) {
		const filesystem::path files{"files"};
		system("cls");
		cout << files << " > " << openUserInput << endl << endl;
		return 0;
	}

	int createFile() {
		int c = 1;
		string text;
		string fileName;

		dirPathCreate();
		while (true) {
			printFileNames();
			cout << endl;

			cout << "Type desired file name:" << endl;
			cin >> fileName;

			//Unique char check
			uCharCheck(fileName);
			if (uCharCheck(fileName) == 0) {
				break;
			}
		}


		//Add .txt to the end of userInput
		string fileName1 = fileName + ".txt";

		//File !exist check
		if (!std::filesystem::exists(filesystem::current_path() / "files" / fileName1)) {
			//Create the file
			ofstream fileName2(filesystem::current_path() / "files" / fileName1);
			fileName2.close();
			system("cls");
		}
		//File exists check
		else if (std::filesystem::exists(filesystem::current_path() / "files" / fileName1)) {
			system("cls");
			cout << "ERROR:0001" << endl << fileName1 << " ALREADY EXISTS!" << endl << endl;
			return 1;
		}
		return 0;
	}

	int noteLoop(fstream& fileName) {
		while (true) {
			string notes;
			string rawNotes;
			string notes1;

			//UserInput
			std::getline(std::cin, rawNotes);

			//`end` Check
			if (rawNotes == "end") {
				fileName.close();
				system("cls");
				return 0;
			}

			//Period check
			if (rawNotes.length() > 0 && rawNotes[rawNotes.length() - 1] != '.') {
				string notes = rawNotes + "." + " ";
				fileName << notes << endl;
			}
			else if (rawNotes.length() > 0 && rawNotes[rawNotes.length() - 1] == '.') {
				string notes = rawNotes + " ";
				fileName << notes << endl;
			}
		}
	}

	int generalEntries(string fullFile, fstream& fileName) {
		while (true) {
			string fname;
			string lname;
			string gender;
			string number;
			int num = rand() % 10000;
			std::string id = std::to_string(num);

			cout << "Type 'end' to leave" << endl << endl;

			// Last name
			cout << "Last name: ";
			cin >> lname;
			//'end' check
			if (lname == "end") {
				system("cls");
				return 0;
			}
			// First name
			cout << "First name: ";
			cin >> fname;
			//'end' check
			if (fname == "end") {
				system("cls");
				return 0;
			}
			// Gender
			cout << "Gender: ";
			cin >> gender;
			//'end' check
			if (gender == "end") {
				system("cls");
				return 0;
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
				return 0;
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
				fileName = fstream(filesystem::current_path() / "files" / fullFile, fstream::out | fstream::app);
				fileName << userText << endl;
				fileName.close();
				cout << "Saved successfully!" << endl;
			}
		}
		return 0;
	}

	int readFile(string fullFile) {
		while (true) {
			string userInput;
			string text;
			int c = 1;

			cout << "Type 'end' to leave" << endl << endl;
			cout << fullFile << ":" << endl;

			//Print  contents
			fstream fileName(filesystem::current_path() / "files" / fullFile, fstream::in | fstream::out | fstream::app);
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
				return 0;
			}
			return 0;
		}
	}

	int opIfStates(fstream& fileName, char userInput1, string fullFile) {
		//Note Check
		const filesystem::path files{"files"};
		if (userInput1 == 'n') {
			dirPathOp(fullFile, userInput1, files);

			cout << "You can start to take notes. When you're done, type 'end'" << endl;

			//Note loop
			noteLoop(fileName);
		}

		//General Entries
		if (userInput1 == 'e') {
			dirPathOp(fullFile, userInput1, files);
			generalEntries(fullFile, fileName);

		}
		//Read from file
		else if (userInput1 == 'r') {
			dirPathOp(fullFile, userInput1, files);
			readFile(fullFile);
		}
		//Delete file
		else if (userInput1 == 'd') {
			fileName.close();
			int result = filesystem::remove(filesystem::current_path() / "files" / fullFile);
			system("cls");
			if (result == 1) {
				cout << fullFile << " has been deleted" << endl << endl;
				return 0;
			}
			else {
				cout << "Error: 0003" << endl << fullFile << " deletion unsuccessful";
				return 1;
			}
		}
		//Back
		else if (userInput1 == 'b') {
			dirPathBack(files);
			return 0;
		}
		//Unknown op
		else if (userInput1 != 'r' && userInput1 != 'e' && userInput1 != 'n') {
			system("cls");
			cout << "ERROR:0002" << endl << "Unknown operator" << endl << endl;
			return 1;
		}
	}

	int fileFound(string fullFile) {
		const filesystem::path files{"files"};
		while (true) {
			fstream fileName(filesystem::current_path() / "files" / fullFile, fstream::out | fstream::app);
			dirPath(fullFile, files);
			cout << fullFile << " has been opened!" << endl;
			cout << endl;

			//Options
			char userInput1 = options(fullFile);

			//If statements
			opIfStates(fileName, userInput1, fullFile);

			return 0;
		}
	}

	int openFile(string userInput) {
		int c = 1;
		string text;
		string fullFile = userInput + ".txt";

		//File found
		if (std::filesystem::exists(filesystem::current_path() / "files" / fullFile)) {
			fileFound(fullFile);
			return 0;
		}
		//File not found
		else if (!std::filesystem::exists(filesystem::current_path() / "files" / fullFile)) {
			fileNotFound(fullFile);
			return 1;
		}
		return 0;
	}

	int createSubFolder() {
		int c = 1;
		string folderName;

		const filesystem::path files{"files"};
		filesystem::path p = filesystem::current_path() / files;
		dirPathCreate();
		while (true) {
			cout << "Files:" << endl;
			for (const auto& entry : filesystem::directory_iterator(files)) {
				if (entry.is_regular_file()) {
					cout << entry.path().filename() << endl;
				}
			}
			cout << endl;

			cout << "Type desired folder name:" << endl;
			cin >> folderName;

			uCharCheckFolder(folderName);
			if (uCharCheckFolder(folderName) == 0) {
				break;
			}
			return 0;
		}
		//Folder !exists check
		filesystem::current_path() = filesystem::current_path() / "files" / folderName;
		if (!std::filesystem::exists(filesystem::current_path() / "files" / folderName)) {
			//Create the folder
			filesystem::create_directories(folderName);
			return 0;
		}
		//Folder exists check
		else if (std::filesystem::exists(filesystem::current_path() / "files" / folderName)) {
			system("cls");
			cout << "ERROR:0001" << endl << folderName << " ALREADY EXISTS!" << endl << endl;
			return 1;
		}
	}

	int createOption(string openUserInput, filesystem::path files) {
		char createUserInput;
		dirPathCreate();
		printFileNames();

		cout << "Type 'b' to go back" << endl;
		cout << "What would you like to create; Folder(F) / Text Doc(T):" << endl;
		cin >> createUserInput;

		createUserInput = (char)tolower(createUserInput);
		if (createUserInput == 'f') {
			createSubFolder();
		}
		else if (createUserInput == 't') {
			createFile();
		}
		else if (createUserInput == 'b') {
			return 0;
		}
		return 0;
	}

	int openFolder(string openUserInput) {
		dirPathSubFolder(openUserInput);
		printFileNamesSubFolder(openUserInput);
		return 0;
	}

	int main() {

		while (true) {

			int c = 1;
			string openUserInput;
			string text;
			filesystem::path p = filesystem::current_path();
			const filesystem::path files{"files"};

			dirPathBack(files);
			//Print file names from 'files'
			printFileNames();

			//User input
			cout << "Which file would you like to open? (TYPE C TO CREATE)" << endl;
			cin >> openUserInput;

			//Create new file
			if (openUserInput == "C" || openUserInput == "c") {
				createOption(openUserInput, files);
			}
			else if (filesystem::is_directory(p / "files" / openUserInput)) {
				openFolder(openUserInput);
			}
			//Open existing file
			else {
				openFile(openUserInput);
			}
		}
	}
