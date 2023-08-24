#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {

	int userInput;
	int userLives = 3;

	srand((unsigned)time(NULL));

	while (userLives > 0) {
		cout << "Pick a number between 1 and 50: ";

		while (true){
		cin >> userInput;
		if (userInput > 50 || userInput < 1) {
			cout << "Out of bounds! Pick again: ";
			continue;
		}
		break;
	}

	int pick = 1 + rand() % 50;

	if (userInput == pick) {
		cout << "Congrats! " << pick << " was correct! \n";
	}
	else {
		userLives--;
		cout << "(Lives: " << userLives << ") Wrong! You lost a life! \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

	cout << "You're out of lives! GAME OVER! \n";
	return 0;
}
