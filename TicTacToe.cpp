#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <vector>
#include <string>
//THIS IS WRITTEN USING OLC GPE, CHECK OUT onelonecoder.com
//Or else
class TicTacToe : public olc::PixelGameEngine
{
public:
	TicTacToe()
	{
		sAppName = "TicTacToe";
	}

private:
	//Square occupied bools
	bool SquareOne = false;
	bool SquareTwo = false;
	bool SquareThree = false;
	bool SquareFour = false;
	bool SquareFive = false;
	bool SquareSix = false;
	bool SquareSeven = false;
	bool SquareEight = false;
	bool SquareNine = false;

	int menu = 0;

	std::string State;
	
	//True = X False = O
	bool Turn = false;

	enum TurnResult { Player1_Win, Player2_Win, No_Win };

	enum Squares { Cross, Circle, Blank };
	std::vector<Squares> SquareVec = { Blank, Blank, Blank, Blank, Blank, Blank, Blank, Blank, Blank };
	enum game { MAIN, PVP, PVM };
	game mode = game::MAIN;

public:
	void MainMenu() {
		Clear(olc::BLACK);
		if (menu == 0) {
			DrawString(10, 50, ">> Player vs Player", olc::WHITE, 1);
			DrawString(10, 70, "Player vs Machine", olc::WHITE, 1);
			DrawString(50, 90, "Exit", olc::RED, 1);
		}
		else if (menu == 1) {
			DrawString(10, 50, "Player vs Player", olc::WHITE, 1);
			DrawString(10, 70, ">> Player vs Machine", olc::WHITE, 1);
			DrawString(50, 90, "Exit", olc::RED, 1);
		}
		else if (menu == 2) {
			DrawString(10, 50, "Player vs Player", olc::WHITE, 1);
			DrawString(10, 70, "Player vs Machine", olc::WHITE, 1);
			DrawString(50, 90, ">> Exit", olc::RED, 1);
		}
		if (GetKey(olc::Key::DOWN).bPressed && menu < 2) {
			menu++;
		}
		else if (GetKey(olc::Key::DOWN).bPressed && menu == 2) {
			menu = 0;
		}
		else if (GetKey(olc::Key::UP).bPressed && menu > 0) {
			menu--;
		}
		else if (GetKey(olc::Key::UP).bPressed && menu == 0) {
			menu = 2;
		}
		if (GetKey(olc::Key::ENTER).bPressed && menu == 0) {
			mode = game::PVP;
		}
	}
	TurnResult WinCheck() {
		//O Win arguments
		//Horizontal wins
		if (SquareVec[0] == Squares::Circle && SquareVec[1] == Squares::Circle && SquareVec[2] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[3] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[5] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[6] == Squares::Circle && SquareVec[7] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//Vertical wins
		else if (SquareVec[0] == Squares::Circle && SquareVec[3] == Squares::Circle && SquareVec[6] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[1] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[7] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[2] == Squares::Circle && SquareVec[5] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//Angle wins
		else if (SquareVec[0] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[2] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[6] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//X Win arguments
		//Horizontal wins
		if (SquareVec[0] == Squares::Cross && SquareVec[1] == Squares::Cross && SquareVec[2] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[3] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[5] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[6] == Squares::Cross && SquareVec[7] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		//Vertical wins
		else if (SquareVec[0] == Squares::Cross && SquareVec[3] == Squares::Cross && SquareVec[6] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[1] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[7] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[2] == Squares::Cross && SquareVec[5] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		//Angle wins
		else if (SquareVec[0] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[2] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[6] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		return TurnResult::No_Win;
	}
	bool OnUserCreate() override {
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		// Draw Boundary
		if (mode == game::MAIN) {
			MainMenu();
		}
		if (mode == game::PVP) {
			Clear(olc::BLACK);
			DrawLine(10, 60, ScreenWidth() - 10, 60, olc::WHITE);
			DrawLine(10, 120, ScreenWidth() - 10, 120, olc::WHITE);
			DrawLine(60, 10, 60, ScreenHeight() - 10, olc::WHITE);
			DrawLine(120, 10, 120, ScreenHeight() - 10, olc::WHITE);

			//Circle Check
			//Square One
			if (GetMouse(0).bPressed && SquareVec[0] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) < 60 && Turn == false) {
				SquareVec[0] = Squares::Circle;
				Turn = true;
			}
			//Square Two
			else if (GetMouse(0).bPressed && SquareVec[1] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
				SquareVec[1] = Squares::Circle;
				Turn = true;
			}
			//Square Three
			else if (GetMouse(0).bPressed && SquareVec[2] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == false) {
				SquareVec[2] = Squares::Circle;
				Turn = true;
			}
			//Square Four
			else if (GetMouse(0).bPressed && SquareVec[3] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
				SquareVec[3] = Squares::Circle;
				Turn = true;
			}
			//Square Five
			else if (GetMouse(0).bPressed && SquareVec[4] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
				SquareVec[4] = Squares::Circle;
				Turn = true;
			}
			//Square Six
			else if (GetMouse(0).bPressed && SquareVec[5] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == false) {
				SquareVec[5] = Squares::Circle;
				Turn = true;
			}
			//Square Seven
			else if (GetMouse(0).bPressed && SquareVec[6] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 120 && Turn == false) {
				SquareVec[6] = Squares::Circle;
				Turn = true;
			}
			//Square Eight
			else if (GetMouse(0).bPressed && SquareVec[7] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 120 && Turn == false) {
				SquareVec[7] = Squares::Circle;
				Turn = true;
			}
			//Square Nine
			else if (GetMouse(0).bPressed && SquareVec[8] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseY()) > 120 && Turn == false) {
				SquareVec[8] = Squares::Circle;
				Turn = true;
			}

			//X Check
			//Square One
			else if (GetMouse(1).bPressed && SquareVec[0] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) < 60 && Turn == true) {
				SquareVec[0] = Squares::Cross;
				Turn = false;
			}
			//Square Two
			else if (GetMouse(1).bPressed && SquareVec[1] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == true) {
				SquareVec[1] = Squares::Cross;
				Turn = false;
			}
			//Square Three
			else if (GetMouse(1).bPressed && SquareVec[2] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 0 && float(GetMouseY()) < 60 && Turn == true) {
				SquareVec[2] = Squares::Cross;
				Turn = false;
			}
			//Square Four
			else if (GetMouse(1).bPressed && SquareVec[3] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == true) {
				SquareVec[3] = Squares::Cross;
				Turn = false;
			}
			//Square Five
			else if (GetMouse(1).bPressed && SquareVec[4] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == true) {
				SquareVec[4] = Squares::Cross;
				Turn = false;
			}
			//Square Six
			else if (GetMouse(1).bPressed && SquareVec[5] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseX()) < 180 && float(GetMouseY()) > 60 && float(GetMouseY()) < 120 && Turn == true) {
				SquareVec[5] = Squares::Cross;
				Turn = false;
			}
			//Square Seven
			else if (GetMouse(1).bPressed && SquareVec[6] == Squares::Blank && float(GetMouseX()) < 60 && float(GetMouseY()) > 120 && Turn == true) {
				SquareVec[6] = Squares::Cross;
				Turn = false;
			}
			//Square Eight
			else if (GetMouse(1).bPressed && SquareVec[7] == Squares::Blank && float(GetMouseX()) > 60 && float(GetMouseX()) < 120 && float(GetMouseY()) > 120 && Turn == true) {
				SquareVec[7] = Squares::Cross;
				Turn = false;
			}
			//Square Nine
			else if (GetMouse(1).bPressed && SquareVec[8] == Squares::Blank && float(GetMouseX()) > 120 && float(GetMouseY()) > 120 && Turn == true) {
				SquareVec[8] = Squares::Cross;
				Turn = false;
			}

			//Draw O
			//Square One
			if (SquareVec[0] == Squares::Circle) {
				DrawCircle(30, 30, 20, olc::WHITE);
			}
			//Square Two
			else if (SquareVec[1] == Squares::Circle) {
				DrawCircle(90, 30, 20, olc::WHITE);
			}
			//Square Three
			else if (SquareVec[2] == Squares::Circle) {
				DrawCircle(150, 30, 20, olc::WHITE);
			}
			//Square Four
			else if (SquareVec[3] == Squares::Circle) {
				DrawCircle(30, 90, 20, olc::WHITE);
			}
			//Square Five
			else if (SquareVec[4] == Squares::Circle) {
				DrawCircle(90, 90, 20, olc::WHITE);
			}
			//Square Six
			else if (SquareVec[5] == Squares::Circle) {
				DrawCircle(150, 90, 20, olc::WHITE);
			}
			//Square Seven
			else if (SquareVec[6] == Squares::Circle) {
				DrawCircle(30, 150, 20, olc::WHITE);
			}
			//Square Eight
			else if (SquareVec[7] == Squares::Circle) {
				DrawCircle(90, 150, 20, olc::WHITE);
			}
			//Square Nine
			else if (SquareVec[8] == Squares::Circle) {
				DrawCircle(150, 150, 20, olc::WHITE);
			}

			//Draw X
			//Square One
			if (SquareVec[0] == Squares::Cross) {
				DrawLine(10, 10, 50, 50, olc::WHITE);
				DrawLine(50, 10, 10, 50, olc::WHITE);
			}
			//Square Two
			else if (SquareVec[1] == Squares::Cross) {
				DrawLine(70, 10, 110, 50, olc::WHITE);
				DrawLine(110, 10, 70, 50, olc::WHITE);
			}
			//Square Three
			else if (SquareVec[2] == Squares::Cross) {
				DrawLine(130, 10, 170, 50, olc::WHITE);
				DrawLine(170, 10, 130, 50, olc::WHITE);
			}
			//Square Four
			else if (SquareVec[3] == Squares::Cross) {
				DrawLine(10, 70, 50, 110, olc::WHITE);
				DrawLine(50, 70, 10, 110, olc::WHITE);
			}
			//Square Five
			else if (SquareVec[4] == Squares::Cross) {
				DrawLine(70, 70, 110, 110, olc::WHITE);
				DrawLine(110, 70, 70, 110, olc::WHITE);
			}
			//Square Six
			else if (SquareVec[5] == Squares::Cross) {
				DrawLine(130, 70, 170, 110, olc::WHITE);
				DrawLine(170, 70, 130, 110, olc::WHITE);
			}
			//Square Seven
			else if (SquareVec[6] == Squares::Cross) {
				DrawLine(10, 130, 50, 170, olc::WHITE);
				DrawLine(50, 130, 10, 170, olc::WHITE);
			}
			//Square Eight
			else if (SquareVec[7] == Squares::Cross) {
				DrawLine(70, 130, 110, 170, olc::WHITE);
				DrawLine(110, 130, 70, 170, olc::WHITE);
			}
			//Square Nine
			else if (SquareVec[8] == Squares::Cross) {
				DrawLine(130, 130, 170, 170, olc::WHITE);
				DrawLine(170, 130, 130, 170, olc::WHITE);
			}

			//Win check
			TurnResult Check = WinCheck();
			if (Check == TurnResult::Player2_Win) {
				Clear(olc::BLACK);
				DrawString(40, 80, "Player 2 Wins!", olc::GREEN, 1);
			}
			else if (Check == TurnResult::Player1_Win) {
				Clear(olc::BLACK);
				DrawString(40, 80, "Player 1 Wins!", olc::GREEN, 1);
			}
		}
		return true;
	} 
};

int main()
{
	TicTacToe demo;
	if (demo.Construct(180, 180, 2, 2))
		demo.Start();
	return 0;
}
