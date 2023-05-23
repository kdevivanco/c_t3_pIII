//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <cstdio>

using namespace std;

//Question #3 - delete_range (2 points)
//Escribir una función template delete_items que permita eliminar un valor específico o una lista de valores de un contenedor secuencial:
//
//Use Case #1:
//
//vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
//auto v3 = delete_range(v1, 1); // {3, 4, 3, 2, 3, 4, 6, 5}
//Use Case #2:
//
//list<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
//auto v3 = delete_range(v1, {1, 4});	 // {3, 3, 2, 3, 6, 5}


#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T, template <class...> class Container>
Container<T> delete_range(Container<T> cont, const T& value) {
    Container<T> result;
    for (const auto& item : cont) {
        if (item != value) {
            result.push_back(item);
        }
    }
    return result;
}

template <typename T, template <class...> class Container>
Container<T> delete_range(Container<T> cont, const Container<T>& values) {
    Container<T> result;
    for (const auto& item : cont) {
        if (find(values.begin(), values.end(), item) == values.end()) {
            result.push_back(item);
        }
    }
    return result;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
