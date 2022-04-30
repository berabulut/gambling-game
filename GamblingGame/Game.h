#pragma once
#include <vector>

#include "Player.h"
#include "Screen.h"


class Game {
private:
	int round = 0;
	double cash = 0;
	std::vector<Player> players;
	Screen screen;

public:
	Game(std::vector<Player> players);

	std::vector<Player> getPlayers();

	bool playRound(int winnerNumber);

	int getRound();
	void incrementRound();

	double getCash();

	void withdrawCash(double cash);
	void depositCash(double cash);

	static bool willEliminatePlayer(Player player);
	void eliminatePlayers();

	Player findWealthiestPlayer();

	void DrawScreen(bool gameEnded, int winnerNumber, Player wealthiestPlayer);
};