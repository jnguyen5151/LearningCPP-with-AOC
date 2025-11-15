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
#include <regex>


namespace aoc{

	// debugging utilities
	void print_array(std::ostream& os, const std::vector<int>& vec);
	
	// Day 1 
	std::pair<std::vector<int>, std::vector<int>> getParsedVectors(std::ifstream& infile);
	int getDistance(std::vector<int>& xVector, std::vector<int>& yVector);
	int getSimilarity(std::vector<int>& xVector, std::vector<int>& yVector);

	// Day 2
	bool checkSafety(std::vector<int>& safetyNumbers);
	bool checkSafetyTolerate(std::vector<int>& safetyNumbers);
	int getSafetyReport(std::ifstream& infile);
	int getSafetyReportTolerate(std::ifstream& infile);

	// Day 3
	int mulScan(std::ifstream& infile);

}


#endif // AOC_H