#include "RoundResultTest.h";

RoundResultTest::RoundResultTest() {
	bool gameEnded = false;
	int winnerNumber = 1;
	int roundPlayed = 1;
	double tableCash = 100.1;
	Player* wealthiestPlayer = new Player("name", 1001, 0.15, 1);
	roundResult = new RoundResult(gameEnded, winnerNumber, roundPlayed, tableCash, wealthiestPlayer);
}

RoundResultTest::~RoundResultTest() {
	delete roundResult;
}

TEST_F(RoundResultTest, GetGameEnded) {
	ASSERT_EQ(false, roundResult->getGameEnded());
}
TEST_F(RoundResultTest, GetWinnerNumber) {
	ASSERT_EQ(1, roundResult->getWinnerNumber());
}
TEST_F(RoundResultTest, GetRoundPlayed) {
	ASSERT_EQ(1, roundResult->getWinnerNumber());
}
TEST_F(RoundResultTest, GetTableCash) {
	ASSERT_EQ(100.1, roundResult->getTableCash());
}

TEST_F(RoundResultTest, GetWealthiestPlayer) {
	ASSERT_EQ("name", roundResult->getWealthiestPlayer().getName());
}