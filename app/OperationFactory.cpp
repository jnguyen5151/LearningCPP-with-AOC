#include "OperationFactory.h"
#include "aocDay1.h"

std::unique_ptr<Operation> makeOperation(const std::string& mode)
{
	static const std::unordered_map<std::string, std::function<std::unique_ptr<Operation>()>> table =
	{
		{"Day 1", []{ return std::make_unique<aocDay1>(); }}
	};

	if (auto it = table.find(mode); it != table.end())
		return it->second();

	return nullptr;
}