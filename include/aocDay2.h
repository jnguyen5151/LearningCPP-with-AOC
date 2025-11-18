#pragma once
#include "Operation.h"

class aocDay2 : public Operation
{
public: 
	int run(std::ifstream& infile, std::string& part) override;
private: 
	bool checkSafety(std::vector<int>& safetyNumbers);
	bool checkSafetyTolerate(std::vector<int>& safetyNumbers);
	int getSafetyReport(std::ifstream& infile);
	int getSafetyReportTolerate(std::ifstream& infile);
};