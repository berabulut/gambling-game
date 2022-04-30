#pragma once
#include "pch.h"
#include "../GamblingGame/Screen.h"
#include "../GamblingGame/Player.h"


class ScreenTest : public ::testing::Test
{
public:
	Screen* screen;
	Player* wealthiestPlayer;
	bool gameEnded;
	int round;
	int tableCash;
	int winnerNumber;
	ScreenTest();
	~ScreenTest();
};