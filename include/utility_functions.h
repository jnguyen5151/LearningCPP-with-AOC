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

	std::ifstream openFile(const std::string& fileName);

}

#endif // UTILITY_FUNCTIONS_H