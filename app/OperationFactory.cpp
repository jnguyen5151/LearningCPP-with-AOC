#include "OperationFactory.h"
#include "aocDay1.h"
#include "aocDay2.h"
#include "aocDay3.h"

std::unique_ptr<Operation> makeOperation(const std::string& mode)
{
	static const std::unordered_map<std::string, std::function<std::unique_ptr<Operation>()>> table =
	{
		{"Day 1",	[]{ return std::make_unique<aocDay1>(); }},
		{"Day 2",	[]{ return std::make_unique<aocDay2>(); }},
		{"Day 3",	[]{ return std::make_unique<aocDay3>(); }}
	};

	if (auto it = table.find(mode); it != table.end())
		return it->second();

	return nullptr;
}