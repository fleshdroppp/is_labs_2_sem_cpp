#include <iostream>
#include "subset.h"

int main() {
    Subset s1(10);
    Subset s2(10);

    s1.addNumber(1);
    s1.addNumber(3);
    s1.addNumber(4);

    s2.addNumber(1);
    s2.addNumber(3);
    s2.addNumber(5);
    s2.addNumber(6);


    std::cout << "Index: " << s1.containsNumber(1) << '\n';

    std::cout << '\n';

    Subset u = s1.findUnion(s2);
    u.printSubset();

    std::cout << '\n';

    Subset i = s1.findIntersection(s2);
    i.printSubset();

    std::cout << '\n';

    s2.removeNumber(6);
    s2.printSubset();
}