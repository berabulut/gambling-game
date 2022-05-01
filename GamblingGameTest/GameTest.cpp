#include "GameTest.h"

GameTest::GameTest() {
	players = {
		Player("p1", 47624.35, 0.58, 5),
		Player("p2", 47620, 0.15, 3)
	};


	game = new Game(players);
}

TEST_F(GameTest, GetPlayers) {
	ASSERT_EQ(players.size(), game->getPlayers().size());
	for (int i = 0; i < players.size(); i++) {
		ASSERT_EQ(players[i].getName(), game->getPlayers()[i].getName());
		ASSERT_EQ(players[i].getCash(), game->getPlayers()[i].getCash());
	}
}

TEST_F(GameTest, GetRound) {
	ASSERT_EQ(0, game->getRound());
}

TEST_F(GameTest, IncrementRound) {
	game->incrementRound();
	ASSERT_EQ(1, game->getRound());
}

TEST_F(GameTest, GetCash) {
	ASSERT_EQ(0, game->getCash());
}

TEST_F(GameTest, DepositCash) {
	double currCash = game->getCash();
	game->depositCash(200);
	ASSERT_EQ(currCash+200, game->getCash());
}

TEST_F(GameTest, WithdrawCash) {
	double currCash = game->getCash();
	game->withdrawCash(200);
	ASSERT_EQ(currCash - 200, game->getCash());
}

TEST_F(GameTest, FindWealthiestPlayer) {
	ASSERT_EQ(players[0].getName(), game->findWealthiestPlayer().getName());

	players[0].setNewCash(false);
	Game* game = new Game(players);
	ASSERT_NE(players[0].getName(), game->findWealthiestPlayer().getName());
	ASSERT_EQ(players[1].getName(), game->findWealthiestPlayer().getName());
	
	delete game;
}

TEST_F(GameTest, WillEliminatePlayer) {
	Player p1 ("p1", 1000, 0.58, 5);
	ASSERT_EQ(false, game->willEliminatePlayer(p1));

	Player p2("p2", 1000, 0.58, 5);
	p2.setNewCash(false);
	ASSERT_EQ(true, game->willEliminatePlayer(p2));
}

TEST_F(GameTest, EliminatePlayers) {
	std::vector<Player> players = {
		Player("p1", 1000, 0.58, 5),
		Player("p2", 1000, 0.15, 3)
	};

	players[0].setNewCash(false);

	Game* g = new Game(players);
	g->eliminatePlayers();

	ASSERT_EQ(1, g->getPlayers().size());
	ASSERT_EQ(players[1].getName(), g->getPlayers()[0].getName());
	ASSERT_EQ(players[1].getCash(), g->getPlayers()[0].getCash());

	delete g;
}



TEST_F(GameTest, PlayRoundGame) {
	Game* g = new Game(players);

	int winnerNumber = 9;
	double tableCash = players[0].calculateRoundBet() + players[1].calculateRoundBet();
	Player wp = players[1];
	wp.setNewCash(false);
	
	RoundResult got = g->playRound(9);


	ASSERT_EQ(false, got.getGameEnded());
	ASSERT_EQ(1, got.getRoundPlayed());
	ASSERT_EQ(tableCash, got.getTableCash());
	ASSERT_EQ(winnerNumber, got.getWinnerNumber());
	ASSERT_EQ(wp.getName(), got.getWealthiestPlayer().getName());

	delete g;
}

GameTest::~GameTest()
{
	delete game;
}

