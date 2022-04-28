// GamblingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#include "FileOperator.h"
#include "Player.h"
#include "Game.h"

int main()
{
    srand(time(0));

    FileOperator fileOperator("Kisiler.txt", "#");
    std::vector<std::vector<std::string>> rows = fileOperator.Parse();
    std::vector<Player> players;

    for (int i = 0; i < rows.size(); i++) {
        std::string name = rows[i][0];
        double startingCash = std::stod(rows[i][1]);
        float betRate = std::stof(rows[i][2]);
        int luckyNumber = std::stoi(rows[i][3]);
        Player player(name, startingCash, betRate, luckyNumber);
        players.push_back(player);
    }

    Game game(players);

    while (game.playRound()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); continue;
    }
}