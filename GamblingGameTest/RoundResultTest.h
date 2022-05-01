#pragma once
#include "pch.h"
#include "../GamblingGame/RoundResult.h"
#include "../GamblingGame/Player.h"


class RoundResultTest : public ::testing::Test
{
public:
	RoundResult* roundResult;
	RoundResultTest();
	~RoundResultTest();
};