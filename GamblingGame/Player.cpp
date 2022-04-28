#include "Player.h"

Player::Player(std::string name, double startingCash, float betRate, int luckyNumber)
{
    this->name = name;
    this->cash = startingCash;
    this->betRate = betRate;
    this->luckyNumber = luckyNumber;
}

std::string Player::getName()
{
    return this->name;
}

bool Player::hasPlayerWonRound(int winnerNumber) {
    return this->luckyNumber == winnerNumber;
}

double Player::getCash()
{
    return this->cash;
}

double Player::calculateRoundBet()
{
    return this->betRate * this->cash;
}

void Player::setNewCash(bool won)
{
    if (won) {
        this->cash += this->calculateRoundBet();
        return;
    }

    this->cash -= this->calculateRoundBet();

}
