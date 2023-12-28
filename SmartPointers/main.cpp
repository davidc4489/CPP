#include "cats.hpp"
#include "sortVector.hpp"
#include "sortVectorThreads.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

int main(){
    std::vector<std::shared_ptr<Cat>> catsVector;
    std::shared_ptr<Cat> cat1 (new Cat(142.4));
    std::shared_ptr<Cat> cat2 (new Cat(22.4));
    std::shared_ptr<Cat> cat3 (new Cat(32.4));
    std::shared_ptr<Cat> cat4 (new Cat(37.4));
    std::shared_ptr<Cat> cat5 (new Cat(46.4));
    std::shared_ptr<Cat> cat6 (new Cat(38.4));
    std::shared_ptr<Cat> cat7 (new Cat(18.4));
    std::shared_ptr<Cat> cat8 (new Cat(8.4));
    std::shared_ptr<Cat> cat9 (new Cat(26.4));


    catsVector.push_back(cat1);
    catsVector.push_back(cat2);
    catsVector.push_back(cat3);
    catsVector.push_back(cat4);
    catsVector.push_back(cat5);
    catsVector.push_back(cat6);
    catsVector.push_back(cat7);
    catsVector.push_back(cat8);
    catsVector.push_back(cat9);


    std::cout << "Unsorted Vector :\n";
    for(std::shared_ptr<Cat> cat : catsVector){
        std::cout << cat->getWeigth() << " ";
    }

    std::cout << "\n";

    sortVectorThreads(catsVector, 4);

    // std::sort(catsVector.begin(), catsVector.end(), compareFunction);

    std::cout << "Sorted Vector :\n";
    for(std::shared_ptr<Cat> cat : catsVector){
        std::cout << cat->getWeigth() << " ";
    }

    std::cout << "\n";

    // std::cout << catsVector[0]->getWeigth() << "\n";

    return 0;
}