#ifndef LAB1_SUBSET_H
#define LAB1_SUBSET_H


class Subset {
public:
    Subset();

    Subset(const Subset &subset);

    ~Subset();

    explicit Subset(int maxSize);

    Subset& operator+=(int num);

    Subset& operator-=(int num);

    Subset operator + (Subset& s1);

    bool operator == (const Subset& s) const;
    bool operator != (const Subset& s) const;

    int containsNumber(int num);

    int getSize() const;

    void printSubset();

    Subset findIntersection(Subset s2);

private:
    int *elements;
    int size;
    int maxSize;
};



#endif //LAB1_SUBSET_H
