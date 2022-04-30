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
	ASSERT_EQ(false, game->willEliminatePlayer(Player("p1", 1001, 0.58, 5)));
	ASSERT_EQ(true, game->willEliminatePlayer(Player("p2", 999, 0.58, 5)));
}

TEST_F(GameTest, EliminatePlayers) {
	std::vector<Player> players = {
		Player("p1", 999, 0.58, 5),
		Player("p2", 1000, 0.15, 3)
	};
	Game* g = new Game(players);
	g->eliminatePlayers();

	ASSERT_EQ(1, g->getPlayers().size());
	ASSERT_EQ(players[1].getName(), g->getPlayers()[0].getName());
	ASSERT_EQ(players[1].getCash(), g->getPlayers()[0].getCash());

	delete g;
}


TEST_F(GameTest, RenderScreen) {
	std::vector<Player> players = {
		Player("p1", 999, 0.58, 5),
		Player("p2", 1000, 0.15, 3)
	};
	Game* g = new Game(players);
	Player wp = g->findWealthiestPlayer();

	ASSERT_NO_THROW(g->DrawScreen(false, 5, wp));
	ASSERT_NO_THROW(g->DrawScreen(true, 5, wp));

	delete g;
}

TEST_F(GameTest, PlayRoundGameContinues) {
	ASSERT_EQ(true, game->playRound(5));
}

TEST_F(GameTest, PlayRoundGameEnds) {
	std::vector<Player> players = {
	Player("p1", 1001, 0.58, 5),
	Player("p2", 1000, 0.58, 3),
	};
	Game* g = new Game(players);
	ASSERT_EQ(false, g->playRound(1));

	delete g;
}

GameTest::~GameTest()
{
	delete game;
}

