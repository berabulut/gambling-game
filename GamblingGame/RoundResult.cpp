#include "RoundResult.h"

RoundResult::RoundResult(bool gameEnded, int winnerNumber, int roundPlayed, double tableCash, Player* wealthiestPlayer)
{
	this->gameEnded = gameEnded;
	this->winnerNumber = winnerNumber;
	this->roundPlayed = roundPlayed;
	this->tableCash = tableCash;
	this->wealthiestPlayer = wealthiestPlayer;
}

RoundResult::~RoundResult() {
	delete this->wealthiestPlayer;
}

bool RoundResult::getGameEnded()
{
	return this->gameEnded;
}

int RoundResult::getWinnerNumber()
{
	return this->winnerNumber;
}

int RoundResult::getRoundPlayed()
{
	return this->roundPlayed;
}

double RoundResult::getTableCash()
{
	return this->tableCash;
}

Player RoundResult::getWealthiestPlayer()
{
	return *this->wealthiestPlayer;
}