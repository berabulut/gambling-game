#include "pch.h"
#include "../GamblingGame/FileOperator.h";

TEST(FileOperatorTest, Parse) {
	FileOperator* fop = new FileOperator("../../../GamblingGameTest/Kisiler.txt", "#");
	std::vector<std::vector<std::string>> rows{
		{"Raphael Adams", "47624.35", "0.58", "5"},
		{"Huseyin Bera Bulut", "1000", "0.6", "2"}
	};

	EXPECT_EQ(rows, fop->Parse());
	delete fop;
}

TEST(FileOperatorTest, ParseFileNotFound) {
	FileOperator* fop = new FileOperator("Kisiler.txt", "#");
	ASSERT_THROW(fop->Parse(), std::invalid_argument);
	delete fop;
}

TEST(FileOperatorTest, ParseFileIsEmpty) {
	FileOperator* fop = new FileOperator("../../../GamblingGameTest/EmptyKisiler.txt", "#");
	ASSERT_THROW(fop->Parse(), std::invalid_argument);
	delete fop;
}
