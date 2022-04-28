#include "pch.h"
#include "../GamblingGame/Player.h";

TEST(PlayerTest, GetName) {
	std::string name = "test";
	Player *p = new Player(name, 0,0,0);
	EXPECT_EQ(name, p->getName());
	delete p;
}

TEST(PlayerTest, GetNameShouldNotBeEqual) {
	Player* p = new Player("name", 0, 0, 0);
	EXPECT_NE("wrong_name", p->getName());
	delete p;
}