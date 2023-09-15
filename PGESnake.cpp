#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

//THIS IS WRITTEN USING OLC GPE, CHECK OUT onelonecoder.com
//Or else
class Snake : public olc::PixelGameEngine {
public:
	Snake() {
		sAppName = "Snake";
	}

private:

public:
	bool OnUserUpdate(float fElapsedTime) override {
		Clear(olc::BLACK);
		//Draw top border
		DrawLine(5, 5, ScreenWidth() - 5, 5, olc::WHITE);
		//Draw left border
		DrawLine(5, 5, 5, ScreenHeight() - 5, olc::WHITE);
		//Draw right border
		DrawLine(ScreenWidth() - 5, 5, ScreenWidth() - 5, ScreenHeight() - 5, olc::WHITE);
		//Draw bottom border
		DrawLine(5, ScreenHeight() - 5, ScreenWidth() - 5, ScreenHeight() - 5, olc::WHITE);

		//Draw Snake
		DrawRect(50, 50, 1, 1, olc::GREEN);
		return true;
	}

	bool OnUserCreate() override {
		return true;
	}
};

int main() {
	Snake demo;
	if (demo.Construct(100, 100, 5, 5))
		demo.Start();
	return 0;
}
