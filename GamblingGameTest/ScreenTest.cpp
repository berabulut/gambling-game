#include "pch.h"
#include "ScreenTest.h";

ScreenTest::ScreenTest()
{
	screen = new Screen();
	wealthiestPlayer = new Player("name", 10000, 0.5, 1);

	gameEnded = false;
	round = 3;
	tableCash = 50000;
	winnerNumber = 7;
}

ScreenTest::~ScreenTest()
{
	delete screen;
}


TEST_F(ScreenTest, Render) {
	ASSERT_NO_THROW(screen->Render(gameEnded, round, tableCash, winnerNumber, *wealthiestPlayer));
}

TEST_F(ScreenTest, RenderTop) {
	ASSERT_NO_THROW(screen->RenderTop(winnerNumber));
}

TEST_F(ScreenTest, RenderMiddle) {
	ASSERT_NO_THROW(screen->RenderMiddle(round, tableCash));
}

TEST_F(ScreenTest, RenderBottom) {
	ASSERT_NO_THROW(screen->RenderBottom(*wealthiestPlayer));
}

TEST_F(ScreenTest, EndingScreen) {
	ASSERT_NO_THROW(screen->EndingScreen(round, tableCash));
}
