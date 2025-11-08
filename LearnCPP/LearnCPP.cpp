// Learning C++ with Advent of Code 2024
// Im pretty bad at coding, so let me know if theres any improvements I could make :) always happy to learn

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>

// utility functions
void print_array(std::ostream& os, const std::vector<int>& vec)
{
	for (const auto value : vec) {
		os << value << ' ';
	}
	std::cout << '\n';
	return;
}

std::ifstream openFile(std::string& fileName)
{

	std::ifstream infile(fileName);

	if (!infile) {
		std::cerr << "Error opening file" << '\n';
		exit(EXIT_FAILURE);
	}

	return infile;
}

// Takes input file with pair values and parses them into 2 vectors
std::pair<std::vector<int>, std::vector<int>> getParsedVectors(std::ifstream& infile)
{
	std::string line{};
	std::vector<int> xVector{};
	std::vector<int> yVector{};
	int xValue{};
	int yValue{};

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		iss >> xValue >> yValue;
		xVector.push_back(xValue);
		yVector.push_back(yValue);
	}

	return std::make_pair(xVector, yVector);

}


// Advent Day 1 Solution Functions
int getAdventDay1P1(std::vector<int>& xVector, std::vector<int>& yVector)
{

	std::sort(xVector.begin(), xVector.end());
	std::sort(yVector.begin(), yVector.end());

	int solution{};
	for (std::size_t i = 0; i < xVector.size(); i++)
	{
		solution += abs(xVector[i] - yVector[i]);
	}

	return solution;
}

int getAdventDay1P2(std::vector<int>& xVector, std::vector<int>& yVector)
{
	std::unordered_map<int, int> yMap;

	for (std::size_t i = 0; i < yVector.size(); i++)
	{
		int vectorValue{ yVector[i] };
		if (yMap.count(vectorValue)) {
			yMap[vectorValue]++;
		}
		else {
			yMap[vectorValue] = 1;
		}
	}

	int solution{};
	for (std::size_t j = 0; j < xVector.size(); j++)
	{
		int searching{ xVector[j] };
		if (yMap.count(searching))
		{
			solution += (yMap[searching] * searching);
		}
	}

	return solution;

}

// Advent Day 2 Solution Functions
bool checkSafety(std::vector<int>& safetyNumbers)
{
	if (safetyNumbers[1] > safetyNumbers[0])
	{
		for (std::size_t i = 1; i < safetyNumbers.size(); i++)
		{
			int diff{ safetyNumbers[i] - safetyNumbers[i-1] };
			if (diff > 3 || diff <= 0)
			{
				return false;
			}
		}
		return true;

	}
	else {
		for (std::size_t i = 1; i < safetyNumbers.size(); i++)
		{
			int diff{ safetyNumbers[i-1] - safetyNumbers[i] };
			if (diff > 3 || diff <= 0)
			{
				return false;
			}
		}
		return true;

	}
}

int getAdventDay2P1(std::ifstream& infile)
{
	std::string line{};
	std::vector<int> safetyNumbers{};
	int value{};
	int solution{ 0 };

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		while (iss >> value)
		{
			safetyNumbers.push_back(value);
		}

		if (checkSafety(safetyNumbers))
		{
			solution++;
		}

		safetyNumbers.clear();

	}
	return solution;
}

int main()
{
	// day 1
	std::string day1File{ "input.txt" };
	std::ifstream infile{ openFile(day1File)};

	std::pair<std::vector<int>, std::vector<int>> parsedPair{ getParsedVectors(infile) };
	std::vector<int> xVector{ parsedPair.first };
	std::vector<int> yVector{ parsedPair.second };

	int solution1{ getAdventDay1P1(xVector, yVector) };

	std::cout << "Solution1: " << solution1 << '\n';

	int solution2{ getAdventDay1P2(xVector, yVector) };

	std::cout << "Solution2: " << solution2 << '\n';

	infile.close();

	// day 2
	std::string day2File{ "input2.txt" };
	std::ifstream infile2{ openFile(day2File) };

	int solution3{ getAdventDay2P1(infile2) };

	std::cout << "Solution3: " << solution3 << '\n';

	return 0;
}
