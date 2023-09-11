#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

//THIS USES olc PGE made by onelonecoder.com

class BreakOut : public olc::PixelGameEngine
{
public:
	BreakOut()
	{
		sAppName = "TUTORIAL - BreakOut Clone";
	}

private:
	float fBatPos = 20.0f;
	float fBatWidth = 40.0f;

	olc::vf2d vBall = { 200.0f, 200.0f };
	float fBatSpeed = 0.4f;

public:
	bool OnUserCreate() override {
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Erase previous frame
		Clear(olc::BLACK);

		// Handle User Input
		if (GetKey(olc::Key::LEFT).bHeld) fBatPos -= fBatSpeed;
		if (GetKey(olc::Key::RIGHT).bHeld) fBatPos += fBatSpeed;

		if (fBatPos < 11.0f) fBatPos = 11.0f;
		if (fBatPos + fBatWidth > float(ScreenWidth()) - 10.0f) fBatPos = float(ScreenWidth()) - 10.0f - fBatWidth;

		if (GetMouse(0).bHeld) {
			vBall = { float(GetMouseX()), float(GetMouseY()) };
		}

		// Draw Boundary
		DrawLine(10, 10, ScreenWidth() - 10, 10, olc::WHITE);
		DrawLine(10, 10, 10, ScreenHeight() - 10, olc::WHITE);
		DrawLine(ScreenWidth() - 10, 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::WHITE);

		// Draw Bat
		FillRect(int(fBatPos), ScreenHeight() - 20, int(fBatWidth), 10, olc::GREEN);

		// Draw Ball
		FillCircle(vBall, 5, olc::CYAN);
		return true;
	}

};

int main()
{
	BreakOut demo;
	if (demo.Construct(512, 480, 2, 2))
		demo.Start();
	return 0;
}
