#include "sortVectorThreads.hpp"
#include "sortVector.hpp"
#include <thread>
#include <algorithm>
#include <vector>

void sortVectorThreads(std::vector<std::shared_ptr<Cat>>& cats, int threadsNum) {
    int portion = cats.size() / threadsNum;
    std::vector<std::thread> threads;

    for (auto i = cats.begin(); i < cats.end(); i += portion) {
        auto end = (i + portion < cats.end()) ? (i + portion) : cats.end();
        threads.push_back(std::thread(std::sort<decltype(i), decltype(compareFunction)>, i, end, compareFunction));
    }

    for (auto& t : threads) {
        t.join();
    }

    for(long unsigned int p = portion; p < cats.size(); p*=2){
        for(auto i = cats.begin(); i + p < cats.end() ; i += (p*2)){
                std::inplace_merge (i, i + p, ((i + (p*2)) < cats.end()) ? i + (p*2) : cats.end(), compareFunction);
        }
    }

}

// En C++, decltype est un opérateur qui permet de déduire automatiquement le type d'une expression ou d'une entité.

// En C++, la fonction join est utilisée avec des objets de type std::thread pour attendre 
//  que le thread associé termine son exécution avant que le programme principal ne continue. 
// L'utilisation de join garantit que toutes les ressources associées au thread sont libérées correctement.
