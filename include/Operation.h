#pragma once
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <regex>
#include <functional>

class Operation
{
public:
	virtual int run(std::ifstream& infile, std::string& part) = 0;
	virtual ~Operation() = default;
};