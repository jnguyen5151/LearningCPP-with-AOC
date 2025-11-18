#include "aocDay2.h"

bool aocDay2::checkSafety(std::vector<int>& safetyNumbers)
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

bool aocDay2::checkSafetyTolerate(std::vector<int>& safetyNumbers)
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

int aocDay2::getSafetyReport(std::ifstream& infile)
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

		if (aocDay2::checkSafety(safetyNumbers))
		{
			solution++;
		}

		safetyNumbers.clear();

	}
	return solution;
}

int aocDay2::getSafetyReportTolerate(std::ifstream& infile)
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

		if (aocDay2::checkSafetyTolerate(safetyNumbers))
		{
			solution++;
		}

		safetyNumbers.clear();

	}
	return solution;
}

int aocDay2::run(std::ifstream& infile, std::string& part)
{

	if (part == "Part 1")
	{
		return aocDay2::getSafetyReport(infile);
	}

	if (part == "Part 2")
	{
		return aocDay2::getSafetyReportTolerate(infile);
	}

	return 0;
}
