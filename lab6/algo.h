#ifndef LAB1_ALGO_H
#define LAB1_ALGO_H

template <typename I, typename F>
bool my_all_of(I begin, I end, F func) {
    for (auto it = begin; it != end; it++) {
        if (!func(*it)) {
            return false;
        }
    }
    return true;
}

template <typename I, typename F>
bool my_is_sorted(I begin, I end, F func) {
    I prev = begin;
    for (auto it = std::next(begin); it != end; it++) {
        if (!func(*prev, *it))
            return false;
        prev = it;
    }
    return true;
}

template <typename I, typename F>
bool my_is_palindrome(I begin, I end, F func) {
    for (auto itLeft = begin, itRight = std::prev(end); itLeft != itRight; itLeft = std::next(itLeft), itRight = std::prev(itRight))
        if (func(*itLeft, *itRight))
            return false;
    return true;
}

#endif
