//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

template<typename T, ::size_t sz>
class fixed_stack{


public:
    vector<T> values;
    fixed_stack() = default;

    fixed_stack(initializer_list<T> lst){

        int c = 0;
        auto it = lst.begin();

        for(; c < sz; ++c) {
            values.push_back(*it);
            ++it;
        }

    }

    const T& top() const{
        //auto it = values.rbegin();
        return values.back();
    }

    void pop(){
        values.pop_back();
    }

    bool push(T Value) {
        //agrega un nuevo valor a la pila, actualiza la posición del tope y retornar true si fue exitoso,
        if(values.size() < sz){
            values.push_back(move(Value));
            return true;;
        }
       else{
           return false;
       }
    }


    bool empty() {
        return values.empty();
    }//retorna true si la pila esta vacía.

    int size(){
        return values.size();
    }

    //typename vector<T>::iterator stack_begin(){return values.begin();}


    ~fixed_stack(){
        values.clear();
    }

    auto end() {
        //auto it = values.rbegin();
        return values.begin();
    }
};


template<typename T, ::size_t sz>
class fixed_stack_pusher {
public:
    using N = typename std::vector<T>::iterator;
    N it;
    fixed_stack<T, sz>& my_stack;

    fixed_stack_pusher(fixed_stack<T, sz>& stack) : my_stack(stack) {
        it = stack.values.end();
        if (!stack.values.empty()) {
            --it;
        }
    }

    fixed_stack_pusher& operator++() {
        if (it != my_stack.values.begin()) {
            --it;
        }
        return *this;
    }

    fixed_stack_pusher operator++(int) {
        fixed_stack_pusher temp = *this;
        ++(*this);
        return temp;
    }

    fixed_stack_pusher& operator=(T value) {
        my_stack.push(value);
        return *this;
    }

    fixed_stack_pusher& operator*() {
        return *this;
    }
};


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
