#ifndef LAB1_SUBSET_H
#define LAB1_SUBSET_H


class Subset {
public:
    Subset();

    Subset(const Subset &subset);

    ~Subset();

    explicit Subset(int maxSize);

    void addNumber(int num);

    int removeNumber(int num);

    int containsNumber(int num);

    int getSize() const;

    void printSubset();

    Subset findUnion(Subset s2);

    Subset findIntersection(Subset s2);

private:
    int *elements;
    int size;
    int maxSize;
};



#endif //LAB1_SUBSET_H
