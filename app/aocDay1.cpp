#include "aocDay1.h"

std::pair<std::vector<int>, std::vector<int>> aocDay1::getParsedVectors(std::ifstream& infile)
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

int aocDay1::getDistance(std::vector<int>& xVector, std::vector<int>& yVector)
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

int aocDay1::getSimilarity(std::vector<int>& xVector, std::vector<int>& yVector)
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

int aocDay1::run(std::ifstream& infile, std::string& part)
{
	std::pair<std::vector<int>, std::vector<int>> parsedPair{ aocDay1::getParsedVectors(infile) };
	std::vector<int> xVector{ parsedPair.first };
	std::vector<int> yVector{ parsedPair.second };

	if (part == "Part 1")
	{
		return aocDay1::getDistance(xVector, yVector);
	}

	if (part == "Part 2")
	{
		return aocDay1::getSimilarity(xVector, yVector);
	}

	return 0;
}