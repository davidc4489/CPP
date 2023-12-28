#pragma once

#include "cats.hpp"
#include <vector>
#include <memory>


void sortVectorThreads(std::vector<std::shared_ptr<Cat>>& catsVector, int threadsNum);