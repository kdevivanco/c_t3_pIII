//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H


//Escribir una función template sum_range que permita la suma de los valores de 2 contenedores.
// Si uno de los contenedores es de menor tamaño, el contenedor de menor tamaño se sumará repetidamente
// con otro contenedor hasta completar el tamaño del mayor.

//vector<int> v1 = {1, 3, 4};
//vector<int> v2 = {4, 5, 6};
//auto v3 = sum_range(v1, v2}; // {5, 8, 10}

//list<int> v1 = {1, 2, 3, 4, 5};
//list<int> v2 = {10, 20};
//auto v3 = sum_range(v1, v2}; // {11, 22, 13, 24, 15}
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <forward_list>
#include <algorithm>
#include <iterator>
using namespace std;


template <typename T>
forward_list<T> sum_range(const forward_list<T>& cont, const forward_list<T>& cont2) {
    forward_list<T> result;

    auto size1 = distance(cont.begin(), cont.end());
    auto size2 = distance(cont2.begin(), cont2.end());
    auto maxSize = max(size1, size2);

    auto it1 = cont.begin();
    auto it2 = cont2.begin();

    for (auto i = 0; i < maxSize; ++i) {
        result.push_front(*it1 + *it2);

        advance(it1, 1);
        if (it1 == cont.end())
            it1 = cont.begin();

        advance(it2, 1);
        if (it2 == cont2.end())
            it2 = cont2.begin();
    }

    result.reverse();
    return result;
}



template <typename T, template <typename...> class Container>
Container<T> sum_range(Container<T> cont, Container<T> cont2) {
    Container<T> result;

    auto size1 = distance(cont.begin(), cont.end());
    auto size2 = distance(cont2.begin(), cont2.end());
    auto maxSize = max(size1, size2);

    auto it1 = cont.begin();
    auto it2 = cont2.begin();

    for (auto i = 0; i < maxSize; ++i) {
        result.emplace_back(*it1 + *it2);

        advance(it1, 1);
        if (it1 == cont.end())
            it1 = cont.begin();

        std::advance(it2, 1);
        if (it2 == cont2.end())
            it2 = cont2.begin();
    }

    return result;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H