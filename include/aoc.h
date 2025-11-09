#pragma once
#ifndef AOC_H
#define AOC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>


namespace aoc{

	void print_array(std::ostream& os, const std::vector<int>& vec);

	std::pair<std::vector<int>, std::vector<int>> getParsedVectors(std::ifstream& infile);
	int getAdventDay1P1(std::vector<int>& xVector, std::vector<int>& yVector);
	int getAdventDay1P2(std::vector<int>& xVector, std::vector<int>& yVector);
	bool checkSafety(std::vector<int>& safetyNumbers);
	bool checkSafetyTolerate(std::vector<int>& safetyNumbers);
	int getAdventDay2P1(std::ifstream& infile);
	int getAdventDay2P2(std::ifstream& infile);

}


#endif // AOC_H