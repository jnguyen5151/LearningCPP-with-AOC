#include "aocDay3.h"

int aocDay3::mulScan(std::ifstream& infile)
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

int aocDay3::mulScanToggle(std::ifstream& infile)
{

}

int aocDay3::run(std::ifstream& infile, std::string& part)
{

	if (part == "Part 1")
	{
		return aocDay3::mulScan(infile);
	}

	if (part == "Part 2")
	{
		return aocDay3::mulScan(infile);
	}

	return 0;
}