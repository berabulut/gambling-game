#pragma once
#include <string>

class Player {
private:
	std::string name;
	double cash;

	// Should be between 0-10 (inclusive)
	int luckyNumber;
	// Should be between 0-1
	float betRate;

public:
	Player(std::string name, double startingCash, float betRate, int luckyNumber);

	std::string getName();
	bool hasPlayerWonRound(int winnerNumber);

	double calculateRoundBet();

	double getCash();
	void setNewCash(bool won);
};