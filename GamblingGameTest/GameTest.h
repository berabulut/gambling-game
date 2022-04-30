#pragma once
#include "pch.h"
#include "../GamblingGame/Screen.h"
#include "../GamblingGame/Player.h"
#include "../GamblingGame/Game.h"


class GameTest : public ::testing::Test
{
public:
	Game* game;
	std::vector<Player> players; 
	GameTest();
	~GameTest();
};
