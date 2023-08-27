#include <iostream>
using namespace std;

int main() {

	int userLives = 3;
	int userInput;

	srand((unsigned)time(NULL));

	while (userLives > 0) {
		cout << "(Lives: " << userLives << ") Pick a number between 1-50: ";

		while (true){
		cin >> userInput;
		if (userInput > 50 || userInput < 1) {
			cout << "Out of bounds. Pick again: ";
			continue;
		}
		break;
	}

	int pick = 1 + (rand() % 50);

	if (userInput == pick) {
		cout << "Congrats! " << pick << " was correct! \n";
	}
	else {
		userLives--;
		cout << "(Lives: " << userLives << ") Wrong! You lost a life! \n";
	}
}
	cout << "You lost all your lives! GAME OVER! \n";
	return 0;
}
