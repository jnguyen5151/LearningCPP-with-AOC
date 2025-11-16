#include "aoc.h"
#include "utility_functions.h"

// Functions for used for AOC solutions

// Takes input file with pair values and parses them into 2 vectors
// used for Day 1 Input File

void aoc::print_array(std::ostream& os, const std::vector<int>& vec)
{
	for (const auto value : vec) {
		os << value << ' ';
	}
	std::cout << '\n';
	return;
}

// Advent Day 1 Solution Functions
std::pair<std::vector<int>, std::vector<int>> aoc::getParsedVectors(std::ifstream& infile)
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

int aoc::getDistance(std::vector<int>& xVector, std::vector<int>& yVector)
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

int aoc::getSimilarity(std::vector<int>& xVector, std::vector<int>& yVector)
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
bool aoc::checkSafety(std::vector<int>& safetyNumbers)
{
	if (safetyNumbers[1] > safetyNumbers[0])
	{
		for (std::size_t i = 1; i < safetyNumbers.size(); i++)
		{
			int diff{ safetyNumbers[i] - safetyNumbers[i - 1] };
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
			int diff{ safetyNumbers[i - 1] - safetyNumbers[i] };
			if (diff > 3 || diff <= 0)
			{
				return false;
			}
		}
		return true;

	}
}

bool aoc::checkSafetyTolerate(std::vector<int>& safetyNumbers)
{
	if (safetyNumbers[1] > safetyNumbers[0])
	{
		for (std::size_t i = 1; i < safetyNumbers.size(); i++)
		{
			int diff{ safetyNumbers[i] - safetyNumbers[i - 1] };
			if (diff > 3 || diff <= 0)
			{
				std::vector<int> iRemoved{ safetyNumbers };
				iRemoved.erase(iRemoved.begin() + i);
				if (checkSafety(iRemoved)) {
					return true;
				}

				std::vector<int> iRemoved2{ safetyNumbers };
				iRemoved2.erase(iRemoved2.begin() + (i - 1));
				if (checkSafety(iRemoved2)) {
					return true;
				}

				std::vector<int> iRemoved0{ safetyNumbers };
				iRemoved0.erase(iRemoved0.begin());
				if (checkSafety(iRemoved0)) {
					return true;
				}

				return false;
			}
		}
		return true;

	}
	else {
		for (std::size_t i = 1; i < safetyNumbers.size(); i++)
		{
			int diff{ safetyNumbers[i - 1] - safetyNumbers[i] };
			if (diff > 3 || diff <= 0)
			{
				std::vector<int> iRemoved{ safetyNumbers };
				iRemoved.erase(iRemoved.begin() + i);
				if (checkSafety(iRemoved)) {
					return true;
				}

				std::vector<int> iRemoved2{ safetyNumbers };
				iRemoved2.erase(iRemoved2.begin() + (i - 1));
				if (checkSafety(iRemoved2)) {
					return true;
				}

				std::vector<int> iRemoved0{ safetyNumbers };
				iRemoved0.erase(iRemoved0.begin());
				if (checkSafety(iRemoved0)) {
					return true;
				}

				return false;
			}
		}
		return true;

	}
}

int aoc::getSafetyReport(std::ifstream& infile)
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

		if (aoc::checkSafety(safetyNumbers))
		{
			solution++;
		}

		safetyNumbers.clear();

	}
	return solution;
}

int aoc::getSafetyReportTolerate(std::ifstream& infile)
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

		if (aoc::checkSafetyTolerate(safetyNumbers))
		{
			solution++;
		}

		safetyNumbers.clear();

	}
	return solution;
}


// Advent Day 3 Solution Functions
int aoc::mulScan(std::ifstream& infile)
{
	std::ostringstream oss{};
	oss << infile.rdbuf();
	std::string fileString{ oss.str() };

	std::regex pattern(R"(mul\s*\(\s*(\d+)\s*,\s*(\d+)\s*\))");

	std::vector<int> products;
	int mulResult{};

	for (std::sregex_iterator it(fileString.begin(), fileString.end(), pattern), end; it != end; ++it) {
		// make sure both groups exist
		if (it->size() >= 3) {
			std::string first = (*it)[1].str();
			std::string second = (*it)[2].str();
			// ensure they’re digits before converting
			if (!first.empty() && !second.empty()) {
				int a = std::stoi(first);
				int b = std::stoi(second);
				mulResult += (a * b);
			}
		}
	}

	return mulResult;
}
