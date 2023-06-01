#include "square.h"


square::square(CVector2D v_, float side_length_, float angle_, CVector2D v) : v(v) {
    v.x = v_.x;
    v.y = v_.y;
    side_length = side_length_;
    angle = angle_;
}

bool square::operator == (const square &sq) const {
    return findSquare() == sq.findSquare();
}

bool square::operator != (const square &sq) const {
    return findSquare() != sq.findSquare();
}

bool square::operator > (const square &sq) const {
    return findSquare() > sq.findSquare();
}

bool square::operator < (const square &sq) const {
    return findSquare() < sq.findSquare();
}

float square::findSquare() const {
    return side_length * side_length;
}

void square::increaseSide(float n) {
    side_length *= n;
}

void square::moveVector(CVector2D v) {
    x = v.x;
    y = v.y;
}


