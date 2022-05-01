#pragma once
#include <vector>

#include "Player.h"
#include "RoundResult.h"



class Game {
private:
	int round = 0;
	double cash = 0;
	std::vector<Player> players;

public:
	Game(std::vector<Player> players);

	std::vector<Player> getPlayers();

	RoundResult playRound(int winnerNumber);

	int getRound();
	void incrementRound();

	double getCash();

	void withdrawCash(double cash);
	void depositCash(double cash);

	static bool willEliminatePlayer(Player player);
	void eliminatePlayers();

	Player findWealthiestPlayer();
};