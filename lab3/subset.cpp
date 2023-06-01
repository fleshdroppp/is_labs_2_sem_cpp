#include "subset.h"
#include "stdexcept"
#include "iostream"

Subset::Subset() {
    maxSize = 3;
    size = 0;
    elements = new int[maxSize];
}

Subset::Subset(int maxSize) {
    this->maxSize = maxSize;
    size = 0;
    elements = new int[maxSize];
}

Subset::Subset(const Subset &s): size(s.size), maxSize(s.maxSize), elements(new int[s.maxSize])  {
    for (int i = 0; i < s.size; i++) {
        elements[i] = s.elements[i];
    }
}

Subset::~Subset() {
    delete[] elements;
}

int Subset::getSize() const {
    return size;
}

Subset &Subset::operator+=(int num) {
    if (size == maxSize) {
        throw std::runtime_error("array overflow");
    }
    elements[size] = num;
    size++;
    return *this;
}

Subset &Subset::operator-=(int num){
    int removeNumberInd = containsNumber(num);
    if (removeNumberInd != -1) {
        size -= 1;
        int *tmpArr = new int[size];
        for (int i = 0; i < size + 1; i++) {
            if (i != removeNumberInd) {
                tmpArr[i < removeNumberInd ? i : i - 1] = elements[i];
            }
        }
        delete[] elements;
        elements = tmpArr;
        return *this;
    } else {
        throw std::runtime_error("subset does not contain number");
    }
}

Subset Subset::operator+(Subset &s2)  {
    Subset unionSubset = s2;
    for (int i = 0; i < size; i++) {
        if (s2.containsNumber(elements[i]) == - 1) {
            unionSubset.maxSize += 1;
            unionSubset.elements[unionSubset.maxSize] = elements[i];
        }
    }
    return unionSubset;
}


int Subset::containsNumber(int num) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == num) {
            return i;
        }
    }
    return -1;
}

void Subset::printSubset() {
    std::cout << "size: " << size << " maxSize: " << maxSize << '\n';
    std::cout << "subset: ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << ' ';
    }
    std::cout << '\n';
}


Subset Subset::findIntersection(Subset s2) {
    Subset interSubset(std::max(size, s2.size));
    for (int i = 0; i < size; i++) {
        if (s2.containsNumber(elements[i]) != -1) {
            interSubset.maxSize += 1;
            interSubset.elements[interSubset.maxSize] = elements[i];
        }
    }
    return interSubset;
}

bool Subset::operator==(const Subset &s) const {
    if (size == s.size) {
        for (int i = 0; i < size; i++) {
            if (elements[i] != s.elements[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Subset::operator!=(const Subset &s) const {
    if (size == s.size) {
        for (int i = 0; i < size; i++) {
            if (elements[i] != s.elements[i]) {
                return true;
            }
        }
        return false;
    }
    return true;
}





