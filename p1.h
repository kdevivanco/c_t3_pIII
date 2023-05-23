//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
#include <vector>
#include<cmath>
#include<iostream>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <deque>
#include <iomanip>
#include <istream>
using namespace std;
//Generar una función template split_range, que reciba como parámetros un contenedor y un número n y permita
// dividir el contenedor en n contenedores, si el valor n no es múltiplo del tamaño del contenedor, los ítems
// restantes de la división deberán ser almacenados en el último contenedor. El resultado o valor de retorno deberá
// ser un contenedor que contenga los contenedores devueltos, siendo vector el contenedor por defecto,
// el template tendrá la posibilidad de personalizar en contenedor de resultado.
//
//Use Case:
//
//dequeue<int> v1 = {1, 2, 3, 4, 5, 6, 7};
//auto resultado = split_range(v1, 3};


template<template<typename...>class Container = vector, typename T>
Container<Container<T>> split_range(Container<T>& input, int n) {
    Container<Container<T>> result;
    int size = distance(input.begin(), input.end());
    if (size == 0 || size == 1) {
        result.push_front(input);
        return result;
    }
    int b = size / n;
    int r = size % n;

    auto it = input.begin();

    for (int i = 0; i < n; i++) {
        int subsize = b + (i < r);
        Container<T> fila;
        for (int j = 0; j < subsize; j++) {
            fila.emplace_front(*it);
            ++it;
        }
        for (auto it1 = fila.begin(); it1 != fila.end(); ++it1) {
            for (auto it2 = next(it1); it2 != fila.end(); ++it2) {
                if (*it2 < *it1) {
                    swap(*it1, *it2);
                }
            }
        }
        result.emplace_front(fila);
    }
    result.reverse();
    return result;
}

template<typename T>
deque<deque<T>> split_range(deque<T>& input, int n) {
    deque<deque<T>> result;
    int size = input.size();
    if (size == 0 || size == 1) {
        result.push_back(input);
        return result;
    }
    int b = size / n;
    int r = size % n;

    auto it = input.begin();

    for (int i = 0; i < n; i++) {
        int subsize = b + (i < r);
        deque<T> fila;
        for (int j = 0; j < subsize; j++) {
            fila.push_back(*it);
            ++it;
        }

        for (size_t j = 1; j < fila.size(); j++) {
            T key = fila[j];
            int k = j - 1;
            while (k >= 0 && fila[k] > key) {
                fila[k + 1] = fila[k];
                k--;
            }
            fila[k + 1] = key;
        }

        result.push_back(fila);
    }

    return result;
}

//// resultado[0] = {1, 2};
//// resultado[1] = {3, 4};
//// resultado[2] = {5, 6, 7};
#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
