#ifndef LAB1_SQUARE_H
#define LAB1_SQUARE_H


#include "vector.h"

class square {
public:
    square(CVector2D v_, float side_length_, float angle, CVector2D v);
    bool operator == (const square& counter) const;
    bool operator != (const square& counter) const;
    bool operator > (const square& counter) const;
    bool operator < (const square& counter) const;
    float findSquare() const;
    void increaseSide(float n);
    void moveVector(CVector2D v);
private:
    CVector2D v;
    float side_length;
    float angle;
};


#endif //LAB1_SQUARE_H
