#pragma once
#include <map>
#include <iostream>
#include <mutex> 
#include <shared_mutex> 
#include <random>

std :: shared_mutex mutex_ ; 

template <typename T, typename U>
class Dictionary{
protected:
    std::map <T, U> map;
    int size;

public:
    Dictionary():size{0}{}
    U find(T key) {
        std:: shared_lock lock ( mutex_ ) ;
        auto it = map.find(key);
        if (it != map.end()) {
            std::cout << "Found ";
            return map[key];
        } else {
            std::cout << "Not found ";
            return 0;
        }
    }
    void insert(T key, U value){
        std:: unique_lock lock ( mutex_ ) ; 
        map.insert(std::pair<T, U>(key, value));
        size++;
    }

    void insertMultiplyValues(U value, int KeysNumber){
        std::random_device rd;  /* Objet pour obtenir une graine aléatoire */
        std::mt19937 gen(rd()); /* Moteur de génération de nombres aléatoires */

        /* Définir la plage du nombre aléatoire (0 à 1000000) */
        std::uniform_int_distribution<int> distribution(0, 1000000);
        int i = 0;
        int randomNumber;
        (void) randomNumber;

        for(i = 0; i < KeysNumber; i++) {
            /* randomNumber = distribution(gen); */
            insert(i, value);
        }
    }

    void print(){
        std::shared_lock lock ( mutex_ ) ;
        for(auto it = map.begin(); it!= map.end(); it++) {
            std::cout << it->first << " : " << it->second << std::endl;
        }
    }

    long getSize() const{
        std:: shared_lock lock ( mutex_ ) ;
        return size;
    }
};
