//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
#include <list>
#include <vector>
#include <iostream>

using namespace std;
//Question #7 - rotate_range (2 points)
//Escribir una función template rotate_range que permite rotar los valores de un contenedor una cantidad determinada,
// esta función recibe 2 parámetros un contenedor, y un valor entero, en caso sea positivo los valores rotará hacia
// la derecha, en caso negativo los valores rotaran a la izquierda:
//
//Use Case #1:
//

template <typename T, template<typename...>class Cont>
Cont<T> rotate_range(Cont<T>& input, int rotnum) {
    int size = distance(begin(input), end(input));
    Cont<T> result;

    if (rotnum < 0) {
        Cont<T> rightside;
        for (int i=0; i<abs(rotnum); i++){
            auto it = input.begin();
            rightside.emplace_back(*it);
            input.erase(it);
        }
        for(const auto& e : input){
            result.emplace_back(e);
        }
        for(const auto& e : rightside){
            result.emplace_back(e);
        }
        return result;
    }
    else {
        Cont<T> rightside;
        for (int i=0; i<rotnum; i++){
            auto it = input.rbegin();
            rightside.emplace_back(*it);
            input.pop_back();
        }
        reverse(begin(rightside),end(rightside));
        for(const auto& e : rightside){
            result.emplace_back(e);
        }
        for(const auto& e : input){
            result.emplace_back(e);
        }

        return result;
    }

    return result;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
