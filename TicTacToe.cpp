#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
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

	//Win argument bools (O)
	bool OSquareOne = false;
	bool OSquareTwo = false;
	bool OSquareThree = false;
	bool OSquareFour = false;
	bool OSquareFive = false;
	bool OSquareSix = false;
	bool OSquareSeven = false;
	bool OSquareEight = false;
	bool OSquareNine = false;
	//Win argument bools (X)
	bool XSquareOne = false;
	bool XSquareTwo = false;
	bool XSquareThree = false;
	bool XSquareFour = false;
	bool XSquareFive = false;
	bool XSquareSix = false;
	bool XSquareSeven = false;
	bool XSquareEight = false;
	bool XSquareNine = false;
	//True = X False = O
	bool Turn = false;

	enum TurnResult { Player1_Win, Player2_Win, No_Win };

public:
	//Win arguments
	TurnResult WinCheck(bool OSquareOne, bool OSquareTwo, bool OSquareThree, bool OSquareFour, bool OSquareFive, bool OSquareSix, bool OSquareSeven, bool OSquareEight, bool OSquareNine, bool XSquareOne, bool XSquareTwo, bool XSquareThree, bool XSquareFour, bool XSquareFive, bool XSquareSix, bool XSquareSeven, bool XSquareEight, bool XSquareNine) {
		//O Win arguments
		//Horizontal wins
		if (OSquareOne == true && OSquareTwo == true && OSquareThree == true) {
			return TurnResult::Player1_Win;
		}
		else if (OSquareFour == true && OSquareFive == true && OSquareSix == true) {
			return TurnResult::Player1_Win;
		}
		else if (OSquareSeven == true && OSquareEight == true && OSquareNine == true) {
			return TurnResult::Player1_Win;
		}
		//Vertical wins
		else if (OSquareOne == true && OSquareFour == true && OSquareSeven == true) {
			return TurnResult::Player1_Win;
		}
		else if (OSquareTwo == true && OSquareFive == true && OSquareEight == true) {
			return TurnResult::Player1_Win;
		}
		else if (OSquareThree == true && OSquareSix == true && OSquareNine == true) {
			return TurnResult::Player1_Win;
		}
		//Angle wins
		else if (OSquareOne == true && OSquareFive == true && OSquareNine == true) {
			return TurnResult::Player1_Win;
		}
		else if (OSquareThree == true && OSquareFive == true && OSquareSeven == true) {
			return TurnResult::Player1_Win;
		}
		//X Win arguments
		//Horizontal wins
		if (XSquareOne == true && XSquareTwo == true && XSquareThree == true) {
			return TurnResult::Player2_Win;
		}
		else if (XSquareFour == true && XSquareFive == true && XSquareSix == true) {
			return TurnResult::Player2_Win;
		}
		else if (XSquareSeven == true && XSquareEight == true && XSquareNine == true) {
			return TurnResult::Player2_Win;
		}
		//Vertical wins
		else if (XSquareOne == true && XSquareFour == true && XSquareSeven == true) {
			return TurnResult::Player2_Win;
		}
		else if (XSquareTwo == true && XSquareFive == true && XSquareEight == true) {
			return TurnResult::Player2_Win;
		}
		else if (XSquareThree == true && XSquareSix == true && XSquareNine == true) {
			return TurnResult::Player2_Win;
		}
		//Angle wins
		else if (XSquareOne == true && XSquareFive == true && XSquareNine == true) {
			return TurnResult::Player2_Win;
		}
		else if (XSquareThree == true && XSquareFive == true && XSquareSeven == true) {
			return TurnResult::Player2_Win;
		}
		return TurnResult::No_Win;
	}
	bool OnUserCreate() override {
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Draw Boundary
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
				OSquareOne = true;
			}
			//Square Two
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareTwo == false) {
				DrawCircle(90, 30, 20, olc::WHITE);
				SquareTwo = true;
				Turn = true;
				OSquareTwo = true;
			}
			//Square Three
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareThree == false) {
				DrawCircle(150, 30, 20, olc::WHITE);
				SquareThree = true;
				Turn = true;
				OSquareThree = true;
			}
			//Square Four
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFour == false) {
				DrawCircle(30, 90, 20, olc::WHITE);
				SquareFour = true;
				Turn = true;
				OSquareFour = true;
			}
			//Square Five
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFive == false) {
				DrawCircle(90, 90, 20, olc::WHITE);
				SquareFive = true;
				Turn = true;
				OSquareFive = true;
			}
			//Square Six
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareSix == false) {
				DrawCircle(150, 90, 20, olc::WHITE);
				SquareSix = true;
				Turn = true;
				OSquareSix = true;
			}
			//Square Seven
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 120 && SquareSeven == false) {
				DrawCircle(30, 150, 20, olc::WHITE);
				SquareSeven = true;
				Turn = true;
				OSquareSeven = true;
			}
			//Square Eight
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 120 && SquareEight == false) {
				DrawCircle(90, 150, 20, olc::WHITE);
				SquareEight = true;
				Turn = true;
				OSquareEight = true;
			}
			//Square Nine
			else if (float(GetMouseX()) > 120 && (float(GetMouseY())) > 120 && SquareNine == false) {
				DrawCircle(150, 150, 20, olc::WHITE);
				SquareNine = true;
				Turn = true;
				OSquareNine = true;
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
				XSquareOne = true;
			}
			//Square Two
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareTwo == false) {
				DrawLine(70, 10, 110, 50, olc::WHITE);
				DrawLine(110, 10, 70, 50, olc::WHITE);
				SquareTwo = false;
				Turn = false;
				XSquareTwo = true;
			}
			//Square Three
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareThree == false) {
				DrawLine(130, 10, 170, 50, olc::WHITE);
				DrawLine(170, 10, 130, 50, olc::WHITE);
				SquareThree = true;
				Turn = false;
				XSquareThree = true;
			}
			//Square Four
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFour == false) {
				DrawLine(10, 70, 50, 110, olc::WHITE);
				DrawLine(50, 70, 10, 110, olc::WHITE);
				SquareFour = true;
				Turn = false;
				XSquareFour = true;
			}
			//Square Five
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFive == false) {
				DrawLine(70, 70, 110, 110, olc::WHITE);
				DrawLine(110, 70, 70, 110, olc::WHITE);
				SquareFive = true;
				Turn = false;
				XSquareFive = true;
			}
			//Square Six
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareSix == false) {
				DrawLine(130, 70, 170, 110, olc::WHITE);
				DrawLine(170, 70, 130, 110, olc::WHITE);
				SquareSix = true;
				Turn = false;
				XSquareSix = true;
			}
			//Square Seven
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 120 && SquareSeven == false) {
				DrawLine(10, 130, 50, 170, olc::WHITE);
				DrawLine(50, 130, 10, 170, olc::WHITE);
				SquareSeven = true;
				Turn = false;
				XSquareSeven = true;
			}
			//Square Eight
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 120 && SquareEight == false) {
				DrawLine(70, 130, 110, 170, olc::WHITE);
				DrawLine(110, 130, 70, 170, olc::WHITE);
				SquareEight = true;
				Turn = false;
				XSquareEight = true;
			}
			//Square Nine
			else if (float(GetMouseX()) > 120 && (float(GetMouseY())) > 120 && SquareNine == false) {
				DrawLine(130, 130, 170, 170, olc::WHITE);
				DrawLine(170, 130, 130, 170, olc::WHITE);
				SquareNine = true;
				Turn = false;
				XSquareNine = true;
			}
		}
		//Win check
		TurnResult Check = WinCheck(OSquareOne, OSquareTwo, OSquareThree, OSquareFour, OSquareFive, OSquareSix, OSquareSeven, OSquareEight, OSquareNine, XSquareOne, XSquareTwo, XSquareThree, XSquareFour, XSquareFive, XSquareSix, XSquareSeven, XSquareEight, XSquareNine);
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
};

int main()
{
	TicTacToe demo;
	if (demo.Construct(180, 180, 2, 2))
		demo.Start();
	return 0;
}
