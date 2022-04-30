#include "pch.h"
#include "../GamblingGame/Player.h";


TEST(PlayerTest, GetName) {
	std::string name = "test";
	Player* p = new Player(name, 0, 0, 0);
	EXPECT_EQ(name, p->getName());
	delete p;
}

TEST(PlayerTest, GetNameShouldNotBeEqual) {
	Player* p = new Player("name", 0, 0, 0);
	EXPECT_NE("wrong_name", p->getName());
	delete p;
}

TEST(PlayerTest, GetCash) {
	double startingCash = 1001.25;
	Player* p = new Player("name", startingCash, 0, 0);
	EXPECT_EQ(startingCash, p->getCash());
	delete p;
}

TEST(PlayerTest, GetCashShouldNotBeEqual) {
	double startingCash = 1001.25;
	Player* p = new Player("name", startingCash, 0, 0);
	EXPECT_NE(startingCash + 10, p->getCash());
	delete p;
}

TEST(PlayerTest, CalculateRoundBet) {
	double startingCash = 47624.35;
	float betRate = 0.58;
	int roundBet = 27622;

	Player* p = new Player("name", startingCash, betRate, 0);
	EXPECT_EQ(roundBet, int(p->calculateRoundBet()));
	delete p;
}

TEST(PlayerTest, CalculateRoundBetShouldNotBeEqual) {
	double startingCash = 47624.35;
	float betRate = 0.58;
	int roundBet = 27622;

	Player* p = new Player("name", startingCash, betRate, 0);
	EXPECT_NE(roundBet - 1, int(p->calculateRoundBet()));
	delete p;
}

TEST(PlayerTest, HasPlayerWonRound) {
	Player* p1 = new Player("name", 0.1, 0.1, 9);
	EXPECT_EQ(true, p1->hasPlayerWonRound(9));
	delete p1;

	Player* p2 = new Player("name", 0.1, 0.1, 7);
	EXPECT_EQ(true, p2->hasPlayerWonRound(7));
	delete p2;

	Player* p3 = new Player("name", 0.1, 0.1, 5);
	EXPECT_EQ(false, p3->hasPlayerWonRound(7));
	delete p3;

	Player* p4 = new Player("name", 0.1, 0.1, 2);
	EXPECT_EQ(false, p4->hasPlayerWonRound(7));
	delete p4;
}

TEST(PlayerTest, SetNewCashLostRound) {
	double startingCash = 47624.35;
	float betRate = 0.58;

	Player* p = new Player("name", startingCash, betRate, 0);
	p->setNewCash(false);
	EXPECT_EQ(int(20002.23), int(p->getCash()));
	delete p;
}

TEST(PlayerTest, SetNewCashWonRound) {
	double startingCash = 47624.35;
	float betRate = 0.58;

	Player* p = new Player("name", startingCash, betRate, 0);
	p->setNewCash(true);
	EXPECT_EQ(int(75246.47), int(p->getCash()));
	delete p;
}


