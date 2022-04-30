#include "Game.h"

Game::Game(std::vector<Player> players)
{
	this->players = players;
}

std::vector<Player> Game::getPlayers()
{
	return this->players;
}

bool Game::playRound(int winnerNumber)
{
	for (int i = 0; i < this->players.size(); i++)
	{
		if (this->players[i].hasPlayerWonRound(winnerNumber)) {
			// Reduce table's cash
			this->withdrawCash(this->players[i].calculateRoundBet());

			// Increase player's cash
			this->players[i].setNewCash(true);

			continue;
		}

		// Increase table's cash
		this->depositCash(this->players[i].calculateRoundBet());

		// Decrease player's cash
		this->players[i].setNewCash(false);
	}

	// Find wealthiest player before eliminating players to escape vector out of range
	Player wealthiestPlayer = findWealthiestPlayer();

	// Eliminate players who has cash under 1000
	eliminatePlayers();

	// Show round's result 
	this->DrawScreen(this->players.size() <= 0, winnerNumber, wealthiestPlayer);

	if (this->players.size() <= 0) {
		// Game is over
		return false;
	}

	incrementRound();

	// Game should continue another round
	return true;
}

int Game::getRound()
{
	return this->round;
}

void Game::incrementRound()
{
	this->round++;
}


double Game::getCash()
{
	return this->cash;
}

void Game::withdrawCash(double cash)
{
	this->cash -= cash;
}

void Game::depositCash(double cash)
{
	this->cash += cash;
}



bool Game::willEliminatePlayer(Player player)
{
	return player.getCash() < 1000;
}



void Game::eliminatePlayers()
{
	this->players.erase(
		std::remove_if(this->players.begin(), this->players.end(), willEliminatePlayer),
		this->players.end());
}

Player Game::findWealthiestPlayer()
{
	Player wealthtiestPlayer = this->players[0];
	for (int i = 1; i < this->players.size(); i++)
	{
		if (wealthtiestPlayer.getCash() < this->players[i].getCash()) {
			wealthtiestPlayer = this->players[i];
		}
	}

	return wealthtiestPlayer;
}

void Game::DrawScreen(bool gameEnded, int winnerNumber, Player wealthiestPlayer)
{
	this->screen.Render(gameEnded, this->getRound(), this->getCash(), winnerNumber, wealthiestPlayer);
}
