#pragma once
#include <map>
#include <iostream>
#include <mutex> 
#include <shared_mutex> 
#include <random>

std :: shared_mutex mutex_ ; 
// std :: mutex mutex_ ; 

template <typename T, typename U>
class Dictionary{
public:
    std::map <T, U> map;
    int size;

public:
    Dictionary():size{0}{}
    U find(T key) {
        // std:: unique_lock lock ( mutex_ ) ; 
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
        if(map.find(key) == map.end()){
            size++;
        }
        map.insert(std::pair<T, U>(key, value));
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
            randomNumber = distribution(gen);
            insert(randomNumber, value);
        }
    }

    void sumFounds(int KeysNumber){
        // std:: unique_lock lock ( mutex_ ) ; 
        // std::shared_lock lock ( mutex_ ) ; 
        std::random_device rd;  
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<int> distribution(0, 1000000);
        int sum = 0;
        for(int i = 0; i < KeysNumber; i++) {
            int randomNumber = distribution(gen);
            if(map.find(randomNumber)!= map.end()) {
                // std::cout << "Find ! " << map[randomNumber] << std::endl;
                sum += map[randomNumber];
            }
        }
        std::cout << "Sum of founds: " << sum << std::endl;
    }

    void print(){
        // std:: unique_lock lock ( mutex_ ) ; 
        std::shared_lock lock ( mutex_ ) ;
        for(auto it = map.begin(); it!= map.end(); it++) {
            std::cout << it->first << " : " << it->second << std::endl;
        }
    }

    long getSize() const{
        // std:: unique_lock lock ( mutex_ ) ; 
        std:: shared_lock lock ( mutex_ ) ;
        return size;
    }
};
