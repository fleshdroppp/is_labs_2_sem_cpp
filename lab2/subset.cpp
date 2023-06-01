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

void Subset::addNumber(int num) {
    if (size == maxSize) {
        throw std::runtime_error("array overflow");
    }
    elements[size] = num;
    size++;
}

int Subset::getSize() const {
    return size;
}

Subset::~Subset() {
    delete[] elements;
}

int Subset::removeNumber(int num) {
    int removeNumberInd = containsNumber(num);
    if (removeNumberInd != -1) {
        int removedNumber = elements[removeNumberInd];
        size -= 1;
        int *tmpArr = new int[size];
        for (int i = 0; i < size + 1; i++) {
            if (i != removeNumberInd) {
                tmpArr[i < removeNumberInd ? i : i - 1] = elements[i];
            }
        }
        delete[] elements;
        elements = tmpArr;
        return removedNumber;
    } else {
        throw std::runtime_error("subset does not contain number");
    }
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

Subset Subset::findUnion(Subset s2) {
    Subset unionSubset = s2;
    for (int i = 0; i < size; i++) {
        if (s2.containsNumber(elements[i]) == - 1) {
            unionSubset.addNumber(elements[i]);
            unionSubset.maxSize += 1;
        }
    }
    return unionSubset;
}

Subset Subset::findIntersection(Subset s2) {
    Subset interSubset(std::max(size, s2.size));
    for (int i = 0; i < size; i++) {
        if (s2.containsNumber(elements[i]) != -1) {
            interSubset.addNumber(elements[i]);
        }
    }
    return interSubset;
}


