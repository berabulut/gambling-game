#include "pch.h"
#include "../GamblingGame/FileOperator.h";

TEST(FileOperatorTest, Parse) {
	FileOperator* fop = new FileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows{
		{"Raphael Adams", "47624.35", "0.58", "5"},
		{"Huseyin Bera Bulut", "1555600", "0.6", "2"}
	};

	EXPECT_EQ(rows, fop->Parse());
	delete fop;
}

