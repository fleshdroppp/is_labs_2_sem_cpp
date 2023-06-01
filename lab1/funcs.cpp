#include "funcs.h"

// Task 1
void modAndWrite(int& a, int& b) {
    if (a > b) {
        a %= b;
    } else {
        b %= a;
    }
}

void modAndWrite(int* a, int* b) {
    if (*a > *b) {
        *a %= *b;
    } else {
        *b %= *a;
    }
}

// Task 2
void inverseNumber(float& a) {
    if (a != 0) {
        a = 1 / a;
    }
}

void inverseNumber(float* a) {
    if (*a != 0) {
        *a = 1 / *a;
    }
}

// Task 3
void inverseCNumber(std::complex<double>& z) {
    z = std::conj(z);
}

void inverseCNumber(std::complex<double>* z) {
    *z = std::conj(*z);
}


// Task 4
void swapTwoRows(std::vector<std::vector<int>>& matrix, int ind1, int ind2) {
    std::vector<int> tmp_row;
    if (ind1 > matrix.size() || ind2 > matrix.size()) {
        return;
    }
    tmp_row = matrix[ind1];
    matrix[ind1] = matrix[ind2];
    matrix[ind2] = tmp_row;
}

void swapTwoRows(std::vector<std::vector<int>>* matrix, int ind1, int ind2) {
    if (ind1 > matrix->size() || ind2 > matrix->size()) {
        return;
    }
    std::vector<int> tmp_row;
    tmp_row = (*matrix)[ind1];
    (*matrix)[ind1] = (*matrix)[ind2];
    (*matrix)[ind2] = tmp_row;
}