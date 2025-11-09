#pragma once
#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>


namespace utils {

	void print_array(std::ostream& os, const std::vector<int>& vec);
	std::ifstream openFile(const std::string& fileName);

}

#endif // UTILITY_FUNCTIONS_H