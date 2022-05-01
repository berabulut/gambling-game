#pragma once
#include "Player.h"
#include <string>
#include <vector>

class RoundResult {
private:
	bool gameEnded;
	int winnerNumber;
	int roundPlayed;
	double tableCash;
	Player* wealthiestPlayer;
public:
	RoundResult(bool, int, int, double, Player* p);
	bool getGameEnded();
	int getWinnerNumber();
	int getRoundPlayed();
	double getTableCash();
	Player getWealthiestPlayer();
	~RoundResult();
};

