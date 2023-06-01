#include "iostream"
#include "vector"
#include "algo.h"
#include "CComplex.h"

template <typename T>
bool pred(T value, T value2) {
    return value == value2;
}

template <typename T>
bool pred2(T value) {
    Complex check{1, 1};
    return value > check;
}

template <typename T>
bool cmp(T first, T second) {
    return first <= second;
}


int main() {
    std::vector<int> a;
    for (int i = -3; i < 10; i++) {
        a.push_back(i);
    }
//    std::cout << my_all_of(a.begin(),   a.end(), pred<int>);
    std::cout << my_is_palindrome(a.begin(), a.end(), pred<int>);
    std::cout << my_is_sorted(a.begin(), a.end(), cmp<int>);

    std::cout << '\n';

    std::vector<Complex> b = {Complex{1.1, 1.2 }, Complex{1.63, 2.32 }, Complex{5.4, 9.1} };

    std::cout << my_is_sorted(b.begin(),   b.end(), cmp<Complex>);
    std::cout << my_all_of(b.begin(),   b.end(), pred2<Complex>);
    std::cout << my_is_palindrome(b.begin(),   b.end(), pred2<Complex>);
}