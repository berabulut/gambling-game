#include "pch.h"
#include "../GamblingGame/RandomNumber.h";

TEST(RandomNumberTest, GenerateNumberBetween) {
	RandomNumber *rn = new RandomNumber();
	for (int i = 0; i < 10000; i++) {
		int randomNumber = rn->GenerateBetween(1, 10);
		// winnerNumber <= 10
		ASSERT_LE(randomNumber, 10);
		// winnerNumber >= 1
		ASSERT_GE(randomNumber, 1);
	}
}