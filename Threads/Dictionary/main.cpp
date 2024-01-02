#include "Dictionary.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

int main(){

    Dictionary<int, int> dic;

    auto start_time = std::chrono::high_resolution_clock::now();

    std::cout << "Size :" << dic.getSize() << std::endl;

    dic.insert(1,5);
    
    std::cout << "Size :" << dic.getSize() << std::endl;
    
    dic.insert(2,6);

    std::cout << "Size :" << dic.getSize() << std::endl;

    std::cout << dic.find(1) << std::endl;
    std::cout << dic.find(3) << std::endl;

    std::thread first(&Dictionary<int, int>::insertMultiplyValues, &dic,3, 300000);
    std::thread second(&Dictionary<int, int>::insertMultiplyValues, &dic,5, 300000);
    std::thread third(&Dictionary<int, int>::insertMultiplyValues, &dic,7, 3000000);
    
    first.join(); 
    second.join();
    third.join();

    std::thread fourth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread fifth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread sixth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread seventh(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread eighth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread ninth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread tenth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread eleventh(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread twelfth(&Dictionary<int, int>::sumFounds, &dic,500);
    std::thread thirteenth(&Dictionary<int, int>::sumFounds, &dic,500); 
    std::thread fourteenth(&Dictionary<int, int>::sumFounds, &dic,5000);
    std::thread fifteenth(&Dictionary<int, int>::sumFounds, &dic,5000);

    fourth.join();
    fifth.join();
    sixth.join();
    seventh.join();
    eighth.join();
    ninth.join();
    tenth.join();
    eleventh.join();
    twelfth.join();
    thirteenth.join();
    fourteenth.join();
    fifteenth.join();

    // dic.insertMultiplyValues(3, 300000);
    // dic.insertMultiplyValues(5, 300000);
    // dic.insertMultiplyValues(7, 3000000);
    // dic.sumFounds(1000);
    // dic.sumFounds(1000);
    // dic.sumFounds(1000);
    // dic.sumFounds(1000);
    // dic.sumFounds(1000);
    // dic.sumFounds(10000);

    // dic.print();
    std::cout << "Size :" << dic.getSize() << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculez la durée d'exécution en millisecondes
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Affichez la durée d'exécution
    std::cout << "Temps d'exécution : " << duration.count() << " millisecondes" << std::endl;

    return 0;
}