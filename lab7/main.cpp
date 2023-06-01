#include <iostream>
#include "CircularBuffer.h"

template <class T>
void output(const CircularBuffer<T>& v) {
    std::cout << "cap: " << v.capacity() << "\n";
    std::cout << "sz: " << v.size() << "\n";
    std::cout << "data: ";
    for (auto it : v)
        std::cout << it << ' ';
    std::cout << "\n\n///\n\n";
}

int main() {
    CircularBuffer<int> test(4);
    test.push_f(1);
    test.push_b(2);
    test.push_b(3);
    test.push_b(4);
    test.push_b(5);
    output(test);

    test.push_f(6);
    output(test);

    test.resize(10);
    test.push_b(7);
    output(test);

    auto buf_it = test.begin();
    buf_it += 11;
    test.insert(buf_it, 8);
    output(test);

    test.remove(13);
    output(test);

    std::cout << std::all_of(test.begin(), test.end(),[](int x) { return x > 0;}) << '\n';
    test.push_b(-1);
    std::cout << std::all_of(test.begin(), test.end(),[](int x) { return x > 0;}) << '\n';


    return 0;
}