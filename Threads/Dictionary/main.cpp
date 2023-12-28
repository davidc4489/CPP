#include "Dictionary.h"
#include <iostream>
#include <random>
#include <thread>

int main(){

    /*  Générer un nombre aléatoire */
    Dictionary<int, int> dic;

    std::cout << "Size :" << dic.getSize() << std::endl;

    dic.insert(1,5);
    
    std::cout << "Size :" << dic.getSize() << std::endl;
    
    dic.insert(2,6);

    std::cout << "Size :" << dic.getSize() << std::endl;

    std::cout << dic.find(1) << std::endl;
    std::cout << dic.find(3) << std::endl;

    std::thread first(&Dictionary<int, int>::insertMultiplyValues, &dic,3, 1000);
    std::thread second(&Dictionary<int, int>::insertMultiplyValues, &dic,5, 1000);
    first.join(); 
    second.join();

    std::cout << "Size :" << dic.getSize() << std::endl;
    dic.print();

    return 0;
}