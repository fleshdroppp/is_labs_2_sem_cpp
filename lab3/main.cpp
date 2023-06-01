#include <iostream>
#include "subset.h"
#include "square.h"

int main() {
    square s(1, 2, 4, CVector2D(0, 0));
    square s2(2, 4, 10, CVector2D(0, 0));

    if (s == s2) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    if (s < s2) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    if (s != s2) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    if (s > s2) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }


}