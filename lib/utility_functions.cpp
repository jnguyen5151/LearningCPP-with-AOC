#include "utility_functions.h"

// utility functions

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
