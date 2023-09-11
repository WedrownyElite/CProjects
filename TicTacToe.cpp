#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

//THIS USES olc PGE made by onelonecoder.com

class TicTacToe : public olc::PixelGameEngine
{
public:
	TicTacToe()
	{
		sAppName = "TicTacToe";
	}

private:
	bool SquareOne = false;
	bool SquareTwo = false;
	bool SquareThree = false;
	bool SquareFour = false;
	bool SquareFive = false;
	bool SquareSix = false;
	bool SquareSeven = false;
	bool SquareEight = false;
	bool SquareNine = false;
	//True = X False = O
	bool Turn = false;

public:
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
			}
			//Square Two
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareTwo == false) {
				DrawCircle(90, 30, 20, olc::WHITE);
				SquareTwo = true;
				Turn = true;
			}
			//Square Three
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareThree == false) {
				DrawCircle(150, 30, 20, olc::WHITE);
				SquareThree = true;
				Turn = true;
			}
			//Square Four
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFour == false) {
				DrawCircle(30, 90, 20, olc::WHITE);
				SquareFour = true;
				Turn = true;
			}
			//Square Five
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFive == false) {
				DrawCircle(90, 90, 20, olc::WHITE);
				SquareFive = true;
				Turn = true;
			}
			//Square Six
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareSix == false) {
				DrawCircle(150, 90, 20, olc::WHITE);
				SquareSix = true;
				Turn = true;
			}
			//Square Seven
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 120 && SquareSeven == false) {
				DrawCircle(30, 150, 20, olc::WHITE);
				SquareSeven = true;
				Turn = true;
			}
			//Square Eight
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 120 && SquareEight == false) {
				DrawCircle(90, 150, 20, olc::WHITE);
				SquareEight = true;
				Turn = true;
			}
			//Square Nine
			else if (float(GetMouseX()) > 120 && (float(GetMouseY())) > 120 && SquareNine == false) {
				DrawCircle(150, 150, 20, olc::WHITE);
				SquareNine = true;
				Turn = true;
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
			}
			//Square Two
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareTwo == false) {
				DrawLine(70, 10, 110, 50, olc::WHITE);
				DrawLine(110, 10, 70, 50, olc::WHITE);
				SquareTwo = false;
				Turn = false;
			}
			//Square Three
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 0 && (float(GetMouseY())) < 60 && SquareThree == false) {
				DrawLine(130, 10, 170, 50, olc::WHITE);
				DrawLine(170, 10, 130, 50, olc::WHITE);
				SquareThree = true;
				Turn = false;
			}
			//Square Four
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFour == false) {
				DrawLine(10, 70, 50, 110, olc::WHITE);
				DrawLine(50, 70, 10, 110, olc::WHITE);
				SquareFour = true;
				Turn = false;
			}
			//Square Five
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareFive == false) {
				DrawLine(70, 70, 110, 110, olc::WHITE);
				DrawLine(110, 70, 70, 110, olc::WHITE);
				SquareFive = true;
				Turn = false;
			}
			//Square Six
			else if (float(GetMouseX()) > 120 && (float(GetMouseX())) < 180 && (float(GetMouseY())) > 60 && (float(GetMouseY())) < 120 && SquareSix == false) {
				DrawLine(130, 70, 170, 110, olc::WHITE);
				DrawLine(170, 70, 130, 110, olc::WHITE);
				SquareSix = true;
				Turn = false;
			}
			//Square Seven
			else if (float(GetMouseX()) < 60 && (float(GetMouseY())) > 120 && SquareSeven == false) {
				DrawLine(10, 130, 50, 170, olc::WHITE);
				DrawLine(50, 130, 10, 170, olc::WHITE);
				SquareSeven = true;
				Turn = false;
			}
			//Square Eight
			else if (float(GetMouseX()) > 60 && (float(GetMouseX())) < 120 && (float(GetMouseY())) > 120 && SquareEight == false) {
				DrawLine(70, 130, 110, 170, olc::WHITE);
				DrawLine(110, 130, 70, 170, olc::WHITE);
				SquareEight = true;
				Turn = false;
			}
			//Square Nine
			else if (float(GetMouseX()) > 120 && (float(GetMouseY())) > 120 && SquareNine == false) {
				DrawLine(130, 130, 170, 170, olc::WHITE);
				DrawLine(170, 130, 130, 170, olc::WHITE);
				SquareNine = true;
				Turn = false;
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
