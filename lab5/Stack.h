//
// Created by Хуснутдинов Аким on 02.04.2023.
//

#ifndef LAB1_STACK_H
#define LAB1_STACK_H

#include <cstdlib>
#include "Exception.h"

template <int N, typename T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(const T& value);
    T pop();
private:
    int top;
    T* array;
};

template <int N, typename T>
Stack<N, T>::Stack() {
    array = new T[N];
    top = 0;
}
template <int N, typename T>
Stack<N, T>::~Stack() {
    delete[] array;
}

template <int N, typename T>
void Stack<N, T>::push(const T& value) {
    if (top == N) {
        throw Exception("Stack overflow");
    }
    else {
        array[top] = value;
        top++;
    }
}

template <int N, typename T>
T Stack<N, T>::pop() {
    T topV = array[top - 1];
    top--;
    if (top < 0) {
        throw Exception("Out of range");
    }
    return topV;
}

#endif //LAB1_STACK_H
