#pragma once
#include "Operation.h"

class aocDay3 : public Operation
{
public:
	int run(std::ifstream& infile, std::string& part) override;
private:
	int mulScan(std::ifstream& infile);
	int mulScanToggle(std::ifstream& infile);
};