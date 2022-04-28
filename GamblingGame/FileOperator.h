#pragma once
#include <string>
#include <vector>

class FileOperator {
private:
	std::string seperator;
	std::string filePath;
public:
	FileOperator(std::string filePath, std::string seperator);
	std::vector<std::vector<std::string>> Parse();
};
