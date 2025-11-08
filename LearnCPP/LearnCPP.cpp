// LearnCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>

// prints Vectors/Arrays
void print_array(std::ostream& os, const std::vector<int>& vec)
{
	for (const auto value : vec) {
		os << value << ' ';
	}
}

//Takes input file with pair values and parses them into 2 vectors
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


//Advent Solution Functions
int getAdvent1(std::vector<int>& xVector, std::vector<int>& yVector)
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



int main()
{

	constexpr auto inputFileName = "input.txt";

	std::ifstream infile(inputFileName);

	if (!infile) {
		std::cerr << "Error opening file" << '\n';
		return EXIT_FAILURE;
	}

	std::pair<std::vector<int>, std::vector<int>> parsedPair { getParsedVectors(infile) };
	std::vector<int> xVector{ parsedPair.first };
	std::vector<int> yVector{ parsedPair.second };

	int solution{ getAdvent1(xVector, yVector) };

	std::cout << "Solution " << solution << '\n';

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
