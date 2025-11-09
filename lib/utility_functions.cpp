#include "utility_functions.h"

// utility functions

// prints vectors despite it being called print_array and randomly snake case XD
void utils::print_array(std::ostream& os, const std::vector<int>& vec)
{
	for (const auto value : vec) {
		os << value << ' ';
	}
	std::cout << '\n';
	return;
}

// file opener
std::ifstream utils::openFile(const std::string& fileName)
{

	std::ifstream infile(fileName);

	if (!infile) {
		std::cerr << "Error opening file" << '\n';
		exit(EXIT_FAILURE);
	}

	return infile;
}
