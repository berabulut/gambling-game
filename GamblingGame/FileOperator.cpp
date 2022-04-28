#include "FileOperator.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

FileOperator::FileOperator(std::string filePath, std::string seperator)
{
	this->filePath = filePath;
	this->seperator = seperator;
}


std::vector<std::vector<std::string>> FileOperator::Parse()
{
	std::ifstream ReadFile(this->filePath);
	std::string row;
	std::string delimiter = this->seperator;

	std::vector<std::vector<std::string>> rows;

	while (getline(ReadFile, row)) {
		std::stringstream ss(row);
		std::string item;

		size_t pos = 0;
		std::string token;
		std::vector<std::string> cols;
		while ((pos = row.find(delimiter)) != std::string::npos) {
			token = row.substr(0, pos);
			cols.push_back(token);
			row.erase(0, pos + delimiter.length());
		}
		cols.push_back(row);
		rows.push_back(cols);
	}

	ReadFile.close();

	return rows;
}
