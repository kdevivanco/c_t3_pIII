//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;
//Question #4 - delete_duplicated (2 points)
//Escribir una función template delete_duplicated que permita eliminar todos los valores duplicados:
//
//Use Case #1:
//
//vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
//auto v2 = delete_duplicated(v1);        // {1, 3, 4, 2, 6, 5}
//Use Case #2:
//
//list<int> v3 = {1, 1, 1, 1, 3, 2, 2, 2, 2, 5};
//auto v4 = delete_duplicated(v3);	    // {1, 3, 2, 5}
template <typename T, template <class...> class Container>
Container<T> delete_duplicated(Container<T> input) {
    Container<T> result;

    for (const auto& item : input) {
        if (find(result.begin(), result.end(), item) == result.end()) {
            result.push_back(item);
        }
    }

    return result;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
