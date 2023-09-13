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
	game mode;

public:
	void MainMenu() {
		while (true) {
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
		}
	}
	TurnResult WinCheck() {
		//O Win arguments
		//Horizontal wins
		if (SquareVec[1] == Squares::Circle && SquareVec[2] == Squares::Circle && SquareVec[3] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[4] == Squares::Circle && SquareVec[5] == Squares::Circle && SquareVec[6] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[7] == Squares::Circle && SquareVec[8] == Squares::Circle && SquareVec[9] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//Vertical wins
		else if (SquareVec[1] == Squares::Circle && SquareVec[4] == Squares::Circle && SquareVec[7] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[2] == Squares::Circle && SquareVec[5] == Squares::Circle && SquareVec[8] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[3] == Squares::Circle && SquareVec[6] == Squares::Circle && SquareVec[9] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//Angle wins
		else if (SquareVec[1] == Squares::Circle && SquareVec[5] == Squares::Circle && SquareVec[9] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		else if (SquareVec[3] == Squares::Circle && SquareVec[5] == Squares::Circle && SquareVec[7] == Squares::Circle) {
			return TurnResult::Player1_Win;
		}
		//X Win arguments
		//Horizontal wins
		if (SquareVec[1] == Squares::Cross && SquareVec[2] == Squares::Cross && SquareVec[3] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[4] == Squares::Cross && SquareVec[5] == Squares::Cross && SquareVec[6] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[7] == Squares::Cross && SquareVec[8] == Squares::Cross && SquareVec[9] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		//Vertical wins
		else if (SquareVec[1] == Squares::Cross && SquareVec[4] == Squares::Cross && SquareVec[7] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[2] == Squares::Cross && SquareVec[5] == Squares::Cross && SquareVec[8] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[3] == Squares::Cross && SquareVec[6] == Squares::Cross && SquareVec[9] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		//Angle wins
		else if (SquareVec[1] == Squares::Cross && SquareVec[5] == Squares::Cross && SquareVec[9] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		else if (SquareVec[3] == Squares::Cross && SquareVec[5] == Squares::Cross && SquareVec[7] == Squares::Cross) {
			return TurnResult::Player2_Win;
		}
		return TurnResult::No_Win;
	}
	bool OnUserCreate() override {
		MainMenu();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		// Draw Boundary
		if (mode == game::PVP) {
			DrawLine(10, 60, ScreenWidth() - 10, 60, olc::WHITE);
			DrawLine(10, 120, ScreenWidth() - 10, 120, olc::WHITE);
			DrawLine(60, 10, 60, ScreenHeight() - 10, olc::WHITE);
			DrawLine(120, 10, 120, ScreenHeight() - 10, olc::WHITE);

			//Draw Circle
			if (GetMouse(0).bPressed && Turn == false) {
				//Square One
				if (float(GetMouseX()) < 60 && (float(GetMouseY())) < 60 && SquareOne == false) {
					DrawCircle(30, 30, 20, olc::WHITE);
					SquareOne = true;
					Turn = true;
					SquareVec[1] = Squares::Circle;
				}
				//Square Two
				else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareTwo == false) {
					DrawCircle(90, 30, 20, olc::WHITE);
					SquareTwo = true;
					Turn = true;
					SquareVec[2] = Squares::Circle;
				}
				//Square Three
				else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareThree == false) {
					DrawCircle(150, 30, 20, olc::WHITE);
					SquareThree = true;
					Turn = true;
					SquareVec[3] = Squares::Circle;
				}
				//Square Four
				else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFour == false) {
					DrawCircle(30, 90, 20, olc::WHITE);
					SquareFour = true;
					Turn = true;
					SquareVec[4] = Squares::Circle;
				}
				//Square Five
				else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFive == false) {
					DrawCircle(90, 90, 20, olc::WHITE);
					SquareFive = true;
					Turn = true;
					SquareVec[5] = Squares::Circle;
				}
				//Square Six
				else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareSix == false) {
					DrawCircle(150, 90, 20, olc::WHITE);
					SquareSix = true;
					Turn = true;
					SquareVec[6] = Squares::Circle;
				}
				//Square Seven
				else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 120 && SquareSeven == false) {
					DrawCircle(30, 150, 20, olc::WHITE);
					SquareSeven = true;
					Turn = true;
					SquareVec[7] = Squares::Circle;
				}
				//Square Eight
				else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 120 && SquareEight == false) {
					DrawCircle(90, 150, 20, olc::WHITE);
					SquareEight = true;
					Turn = true;
					SquareVec[8] = Squares::Circle;
				}
				//Square Nine
				else if (float(GetMouseX()) > 120 && (float(GetMouseY())) > 120 && SquareNine == false) {
					DrawCircle(150, 150, 20, olc::WHITE);
					SquareNine = true;
					Turn = true;
					SquareVec[9] = Squares::Circle;
				}
			}
			//Draw X
			else if (GetMouse(1).bPressed && Turn == true) {
				//Square One
				if (float(GetMouseX()) < 60 && (float(GetMouseY())) < 60 && SquareOne == false) {
					DrawLine(10, 10, 50, 50, olc::WHITE);
					DrawLine(50, 10, 10, 50, olc::WHITE);
					SquareOne = true;
					Turn = false;
					SquareVec[1] = Squares::Cross;
				}
				//Square Two
				else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareTwo == false) {
					DrawLine(70, 10, 110, 50, olc::WHITE);
					DrawLine(110, 10, 70, 50, olc::WHITE);
					SquareTwo = false;
					Turn = false;
					SquareVec[2] = Squares::Cross;
				}
				//Square Three
				else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareThree == false) {
					DrawLine(130, 10, 170, 50, olc::WHITE);
					DrawLine(170, 10, 130, 50, olc::WHITE);
					SquareThree = true;
					Turn = false;
					SquareVec[3] = Squares::Cross;
				}
				//Square Four
				else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFour == false) {
					DrawLine(10, 70, 50, 110, olc::WHITE);
					DrawLine(50, 70, 10, 110, olc::WHITE);
					SquareFour = true;
					Turn = false;
					SquareVec[4] = Squares::Cross;
				}
				//Square Five
				else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFive == false) {
					DrawLine(70, 70, 110, 110, olc::WHITE);
					DrawLine(110, 70, 70, 110, olc::WHITE);
					SquareFive = true;
					Turn = false;
					SquareVec[5] = Squares::Cross;
				}
				//Square Six
				else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareSix == false) {
					DrawLine(130, 70, 170, 110, olc::WHITE);
					DrawLine(170, 70, 130, 110, olc::WHITE);
					SquareSix = true;
					Turn = false;
					SquareVec[6] = Squares::Cross;
				}
				//Square Seven
				else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 120 && SquareSeven == false) {
					DrawLine(10, 130, 50, 170, olc::WHITE);
					DrawLine(50, 130, 10, 170, olc::WHITE);
					SquareSeven = true;
					Turn = false;
					SquareVec[7] = Squares::Cross;
				}
				//Square Eight
				else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 120 && SquareEight == false) {
					DrawLine(70, 130, 110, 170, olc::WHITE);
					DrawLine(110, 130, 70, 170, olc::WHITE);
					SquareEight = true;
					Turn = false;
					SquareVec[8] = Squares::Cross;
				}
				//Square Nine
				else if (float(GetMouseX()) > 120 && (float(GetMouseY())) > 120 && SquareNine == false) {
					DrawLine(130, 130, 170, 170, olc::WHITE);
					DrawLine(170, 130, 130, 170, olc::WHITE);
					SquareNine = true;
					Turn = false;
					SquareVec[9] = Squares::Cross;
				}
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
			return true;
		}
	}
};

int main()
{
	TicTacToe demo;
	if (demo.Construct(180, 180, 2, 2))
		demo.Start();
	return 0;
}
