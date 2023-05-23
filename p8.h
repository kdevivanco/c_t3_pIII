//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <deque>
#include <string>
#include <forward_list>

using namespace std;

template<template <typename...> class Cont = vector>
Cont<string> filter_codes(string filename, char letter){
    ifstream filef;
    Cont<string> result;
    filef.open(filename, ios::in);

    // Checking whether the file is open.
    if (filef.is_open()) {
        string sa;
        // Read data from the file object and put it into a string.
        while (getline(filef, sa)) {
            // Print the data of the string.
            if(sa[0] == letter){
                result.emplace_back(sa);
            }
        }

        // Close the file object.
        filef.close();
    }
    sort(begin(result),end(result));
    return result;
}
//Question #8 - (2 points)
// Escribir una función filter_codes que lea de un archivo una lista de códigos y que retorne de forma ordenada
// todos aquellos códigos que empiecen un carácter, el contenedor de retorno por default es un std::vector pero
// podrá seleccionarse cualquier otro repositorio secuencial (std::deque, std::list o std::forward_list).
//
//NOTA: Los códigos están conformados por 4 letras en minúsculas iniciales y 3 digito de 0 a 9.
//Use Case #1:
//vector<string> codes = filter_codes('data.txt', 'c');
//// Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
//// codes almacenaría ordenadamente: "cabd123", "cdbe546"
//Use Case #2:
//
//auto codes = filter_codes<list>('data.txt', 'c');
//// Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
//// codes almacenaría ordenadamente: "cabd123", "cdbe546"
//Use Case #3:
//
//auto codes = filter_codes<deque>('data.txt', 'c');
//// Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
//// codes almacenaría ordenadamente: "cabd123", "cdbe546"
//Use Case #4:
//
//auto codes = filter_codes<forward_list>('data.txt', 'c');
//// Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
//// codes almacenaría ordenadamente: "cabd123", "cdbe546"
#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
