#include "Player.h"
#include <stdexcept>

Player::Player(std::string name, double startingCash, float betRate, int luckyNumber)
{
    if (name.compare("") == 0) {
        throw std::invalid_argument("Player cannot have empty name");
    }

    if (startingCash < 1000) {
        std::string exceptionMessage = "Player cannot have cash less than 1000 while starting game\nPlayer: "  + name;
        throw std::invalid_argument(exceptionMessage);
    }

    if (betRate <= 0 || betRate > 1) {
        std::string exceptionMessage = "Player should have bet rate more than 0 and less equal than 1\nPlayer: " + name;
        throw std::invalid_argument(exceptionMessage);
    }

    if (luckyNumber > 10 || luckyNumber < 1) {
        std::string exceptionMessage = "Player should have lucky number bigger than 0 less than 11 \nPlayer: " + name;
        throw std::invalid_argument(exceptionMessage);
    }

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
        this->cash += this->calculateRoundBet() * 10;
        return;
    }

    this->cash -= this->calculateRoundBet();

}
