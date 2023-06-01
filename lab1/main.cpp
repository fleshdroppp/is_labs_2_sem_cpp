#include "iostream"
#include "funcs.h"
#include "complex"

int main() {
    // Test 1.1
    int a = 3, b = 10;
    modAndWrite(a, b);
    assert(a == 3 && b == 1);

    // Test 1.2
    a = 10, b = 4;
    modAndWrite(&a, &b);
    assert(a == 2 && b == 4);

    // Test 2.1
    float c = 5;
    inverseNumber(c);
    assert(c * 5 == 1);

    // Test 2.2
    c = 10;
    inverseNumber(&c);
    assert(c * 10 == 1);

    // Test 3.1
    std::complex<double> s(3, 1);
    inverseCNumber(s);
    assert(s.imag() == -1 && s.real() == 3);

    // Test 3.2
    inverseCNumber(&s);
    assert(s.imag() == 1 && s.real() == 3);

    // Test 4.1
    std::vector<std::vector<int>> matrix {{1, 2}, {3, 4}};
    std::vector<std::vector<int> > testMatrix {{3, 4}, {1, 2}};

    swapTwoRows(matrix, 0, 1);
    assert(matrix == testMatrix);

    // Test 4.2
    swapTwoRows(&matrix, 0, 1);
    swapTwoRows(&testMatrix, 0, 1);
    assert(matrix == testMatrix);

    std::cout << "All tests passed!";
}