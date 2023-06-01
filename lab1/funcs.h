//
// Created by Хуснутдинов Аким on 12.02.2023.
//
#ifndef LAB1_FUNCS_H
#define LAB1_FUNCS_H

#include "complex"
#include "vector"

// Task 1
void modAndWrite(int& a, int& b);
void modAndWrite(int* a, int* b);

// Task 2
void inverseNumber(float& a);
void inverseNumber(float* a);

// Task 3
void inverseCNumber(std::complex<double>& z);
void inverseCNumber(std::complex<double>* z);

// Task 4
void swapTwoRows(std::vector<std::vector<int>>& matrix, int ind1, int ind2);
void swapTwoRows(std::vector<std::vector<int>>* matrix, int ind1, int ind2);

#endif //LAB1_FUNCS_H