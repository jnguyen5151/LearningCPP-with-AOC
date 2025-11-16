#pragma once
#include <memory>
#include <string>
#include "Operation.h"

std::unique_ptr<Operation> makeOperation(const std::string& day);