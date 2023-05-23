//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H

#include <iostream>
#include <list>
#include <vector>
#include <tuple>
using namespace std;
template <class... Conts>
auto zip(Conts&&... conts) {
    auto package = {conts...};
    using M = typename decltype(package)::value_type;
    vector<list<typename M::value_type>> result;

    size_t size = min({conts.size()...});

    for (size_t i = 0; i < size; ++i) {
        list<typename M::value_type> lst;

        ((lst.push_back(*next(begin(conts), i))), ...);

        result.push_back(lst);
    }

    return result;
}






#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
