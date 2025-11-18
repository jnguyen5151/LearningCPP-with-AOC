#pragma once
#include "Operation.h"

std::unique_ptr<Operation> makeOperation(const std::string& day);