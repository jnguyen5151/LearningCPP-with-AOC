// Learning/Practicing C++ with Advent of Code 2024
// Im pretty bad at coding, so let me know if theres any improvements I could make :) always happy to learn

#include "utility_functions.h"
#include "aoc.h"


int main()
{
	// day 1
	std::string day1File{ "input.txt" };
	std::ifstream infile{ utils::openFile(day1File)};

	std::pair<std::vector<int>, std::vector<int>> parsedPair{ aoc::getParsedVectors(infile) };
	std::vector<int> xVector{ parsedPair.first };
	std::vector<int> yVector{ parsedPair.second };

	int solution1{ aoc::getAdventDay1P1(xVector, yVector) };

	std::cout << "Solution1: " << solution1 << '\n';

	int solution2{ aoc::getAdventDay1P2(xVector, yVector) };

	std::cout << "Solution2: " << solution2 << '\n';

	infile.close();

	// day 2
	std::string day2File{ "input2.txt" };
	std::ifstream infile2{ utils::openFile(day2File) };

	int solution3{ aoc::getAdventDay2P1(infile2) };

	std::cout << "Solution3: " << solution3 << '\n';

	return 0;
}
