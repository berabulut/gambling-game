#include "Screen.h"

#include <iostream>


void FillRowWithSymbol() {
	for (int i = 0; i < 45; i++) std::cout << "#";
}

void LeftSpace() {
	for (int i = 0; i < 13; i++) std::cout << " ";
}

void LeftSpaceForCash() {
	for (int i = 0; i < 7; i++) std::cout << " ";
}

void RightSpace(int digitCount, int spaceAvailable) {
	for (int i = 0; i < spaceAvailable + 1 - digitCount; i++) std::cout << " ";
}

void PositionTableToMiddle() {
	for (int i = 0; i < 25; i++) std::cout << " ";
}

int Screen::countDigit(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return count;
}


void Screen::RenderTop(int winnerNumber) {
	PositionTableToMiddle(); FillRowWithSymbol(); std::cout << "\n";
	PositionTableToMiddle(); std::cout << "##"; LeftSpace(); std::cout << "SANSLI SAYI: " << winnerNumber; RightSpace(this->countDigit(winnerNumber), 14); std::cout << "##\n";
	PositionTableToMiddle(); FillRowWithSymbol(); std::cout << "\n";
}

void Screen::RenderMiddle(int round, int tableCash) {
	PositionTableToMiddle(); FillRowWithSymbol(); std::cout << "\n";
	PositionTableToMiddle(); std::cout << "##"; LeftSpace(); std::cout << "TUR: " << round; RightSpace(this->countDigit(round), 22); std::cout << "##\n";

	PositionTableToMiddle(); std::cout << "##"; LeftSpaceForCash(); std::cout << "MASA BAKIYE: " << tableCash << " TL"; RightSpace(this->countDigit(tableCash), 17); std::cout << "##\n";

	PositionTableToMiddle(); std::cout << "##                                         ##\n";
	PositionTableToMiddle(); std::cout << "##-----------------------------------------##\n";
}

void Screen::RenderBottom(Player player) {
	PositionTableToMiddle(); std::cout << "##"; LeftSpace(); std::cout << "EN ZENGIN KISI"; RightSpace(0, 13); std::cout << "##\n";

	PositionTableToMiddle(); std::cout << "##"; LeftSpace(); std::cout << player.getName(); RightSpace(player.getName().length(), 27); std::cout << "##\n";
	PositionTableToMiddle(); std::cout << "##"; LeftSpaceForCash(); std::cout << "BAKIYESI: " << int(player.getCash()); RightSpace(this->countDigit(player.getCash()), 23); std::cout << "##\n";
	PositionTableToMiddle(); std::cout << "##                                         ##\n";
	PositionTableToMiddle(); FillRowWithSymbol(); std::cout << "\n";
}

void Screen::EndingScreen(int round, int tableCash)
{
	RenderMiddle(round, tableCash);
	PositionTableToMiddle(); std::cout << "##             OYUN BITTI                  ##\n";
	PositionTableToMiddle(); std::cout << "##                                         ##\n";
	PositionTableToMiddle(); std::cout << "##                                         ##\n";
	PositionTableToMiddle(); FillRowWithSymbol(); std::cout << "\n";
}

void Screen::Render(bool gameEnded, int round, int tableCash, int winnerNumber, Player wealthiestPlayer)
{
	system("CLS");

	if (gameEnded) {
		EndingScreen(round, tableCash);
		return;
	}

	std::cout << "\n\n\n\n";
	RenderTop(winnerNumber);
	RenderMiddle(round, tableCash);
	RenderBottom(wealthiestPlayer);
	std::cout << "\n\n\n";
}