#pragma once
#include "Operation.h"

class aocDay1 : public Operation
{
public: 
	int run(std::ifstream& infile, std::string& part) override;
	int getDistance(std::vector<int>& xVector, std::vector<int>& yVector);
	int getSimilarity(std::vector<int>& xVector, std::vector<int>& yVector);
private:
	std::pair<std::vector<int>, std::vector<int>> getParsedVectors(std::ifstream& infile);
};