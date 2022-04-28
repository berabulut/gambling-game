#pragma once
#include "Player.h"

class Screen {
public:
	void Render(
		bool gameEnded,
		int round,
		int tableCash,
		int winnerNumber,
		Player wealthiestPlayer
	);
	int countDigit(int n);

	void RenderTop(int winnerNumber);
	void RenderMiddle(int round, int tableCash);
	void RenderBottom(Player player);
	void EndingScreen(int round, int tableCash);
};