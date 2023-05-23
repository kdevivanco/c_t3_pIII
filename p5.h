//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

//Question #5 - unpack (2 points)
//La librería estándar de C++ brinda un contenedor simple conocido como std::tuple, que permite almacenar valores de diferente tipo, ejemplo:
//
//std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
//El acceso a sus valores es por medio de la función template std::get
// cuyo parámetro de template se utiliza para identificar la posición de alguno de sus valores.
//
//std::cout << std::get<0>(tup1) << endl; // 1321
//std::cout << std::get<1>(tup1) << endl; // Jose
//std::cout << std::get<2>(tup1) << endl; // Perez
//std::cout << std::get<3>(tup1) << endl; // 1.68
//Lenguajes como python brindan un mecanismo conocido como unpack
// que permita asignar valores de un contenedor a variable con nombres significativos. Por ejemplo en python:
//
//tup1 = (1321, 'Jose', 'Perez', 1.68)
//id, first_name, last_name, height = tup1
//print(id, name, last_name, height)
//Diseñar y desarrollar la función template unpack que permita desempaqueta los valores de una tupla en variables individuales.
//std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
//int key;
//string first_name;
//string last_name;
//double height;
//unpack(key, first_name, last_name, height) = t1;
//std::cout << key <<  " "<< first_name << last_name << height << endl;

template <class ... Vars>
tuple<Vars&...> unpack(Vars&... var) {
    tuple<Vars&...> pack(var...);
    return pack;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
