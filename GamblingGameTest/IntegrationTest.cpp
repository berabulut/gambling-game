#include "pch.h"
#include "../GamblingGame/FileOperator.h";
#include "../GamblingGame/Player.h";
#include "../GamblingGame/Game.h";
#include "../GamblingGame/RoundResult.h";
#include "../GamblingGame/RandomNumber.h";
#include "../GamblingGame/Screen.h";

TEST(IntegrationTest, CannotStartGameWithEmptyPlayerName) {
	FileOperator fileOperator("../../../GamblingGameTest/KisiNameProblem.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	ASSERT_ANY_THROW(Player player(name, startingCash, betRate, luckyNumber));
}

TEST(IntegrationTest, CannotStartGameWithCashLessThan1000) {
	FileOperator fileOperator("../../../GamblingGameTest/KisiCashProblem.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	ASSERT_ANY_THROW(Player player(name, startingCash, betRate, luckyNumber));
}

TEST(IntegrationTest, CannotStartGameWithInvalidBetRate) {
	FileOperator fileOperator("../../../GamblingGameTest/KisiBetRateProblem.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	ASSERT_ANY_THROW(Player player(name, startingCash, betRate, luckyNumber));
}

TEST(IntegrationTest, CannotStartGameWithInvalidLuckyNumber) {
	FileOperator fileOperator("../../../GamblingGameTest/KisiLuckyNumberProblem.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	ASSERT_ANY_THROW(Player player(name, startingCash, betRate, luckyNumber));
}

TEST(IntegrationTest, TableCashCanBeLessThanZero) {
	FileOperator fileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	std::vector<Player> players = {
		Player(name, startingCash, betRate, luckyNumber)
	};

	Game* g = new Game(players);
	RoundResult rr = g->playRound(5);

	ASSERT_EQ(true, rr.getTableCash() < 0);

	delete g;
}

// If player wins round, money betted by player should be multiplied by 10
TEST(IntegrationTest, PlayerWinRound) {
	FileOperator fileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	std::vector<Player> players = {
		Player(name, startingCash, betRate, luckyNumber)
	};

	Game* g = new Game(players);
	RoundResult rr = g->playRound(5);
	
	double expected = players[0].getCash() + players[0].calculateRoundBet() * 10;

	ASSERT_EQ(expected, rr.getWealthiestPlayer().getCash());

	delete g;
}

// If player loses round, player only loses the money he bets
TEST(IntegrationTest, PlayerLoseRound) {
	FileOperator fileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	std::vector<Player> players = {
		Player(name, startingCash, betRate, luckyNumber)
	};

	Game* g = new Game(players);
	RoundResult rr = g->playRound(1);

	double expected = players[0].getCash() - players[0].calculateRoundBet();

	ASSERT_EQ(expected, rr.getWealthiestPlayer().getCash());

	delete g;
}

// Game continues until there is a player has more cash than 1000
TEST(IntegrationTest, GameContinues) {
	FileOperator fileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[0][0];
	double startingCash = std::stod(rows[0][1]);
	float betRate = std::stof(rows[0][2]);
	int luckyNumber = std::stoi(rows[0][3]);

	std::vector<Player> players = {
		Player(name, startingCash, betRate, luckyNumber)
	};

	Game* g = new Game(players);
	RoundResult rr = g->playRound(1);

	ASSERT_EQ(false, rr.getGameEnded());

	delete g;
}

// Game ends when every player eliminated
TEST(IntegrationTest, GameEnds) {
	FileOperator fileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	std::string name = rows[1][0];
	double startingCash = std::stod(rows[1][1]);
	float betRate = std::stof(rows[1][2]);
	int luckyNumber = std::stoi(rows[1][3]);

	std::vector<Player> players = {
		Player(name, startingCash, betRate, luckyNumber)
	};

	Game* g = new Game(players);
	RoundResult rr = g->playRound(1);

	ASSERT_EQ(true, rr.getGameEnded());

	delete g;
}

TEST(IntegrationTest, SimulateGame) {
	FileOperator fileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows = fileOperator.Parse();

	srand(time(0));


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
	RandomNumber randomNumber;
	Screen screen;

	while (true) {
		int winnerNumber = randomNumber.GenerateBetween(1, 10);
		RoundResult roundResult = game.playRound(winnerNumber);
		ASSERT_NO_THROW(screen.Render(
			roundResult.getGameEnded(),
			roundResult.getRoundPlayed(),
			roundResult.getTableCash(),
			roundResult.getWinnerNumber(),
			roundResult.getWealthiestPlayer()
		));

		ASSERT_NO_THROW(roundResult.getGameEnded());
		
		Game* g = new Game(players);
		ASSERT_NO_THROW(g->playRound(winnerNumber));
		delete g;

		if (roundResult.getGameEnded()) break;
	}
}