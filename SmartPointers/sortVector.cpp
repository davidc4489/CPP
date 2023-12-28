#include "sortVector.hpp"

bool compareFunction(std::shared_ptr<Cat> cat1, std::shared_ptr<Cat> cat2){
    return cat1->getWeigth() < cat2->getWeigth();
};