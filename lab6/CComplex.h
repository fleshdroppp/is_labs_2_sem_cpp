#ifndef LAB1_CCOMPLEX_H
#define LAB1_CCOMPLEX_H

#include "cmath"

class Complex {
private:
    double re_;
    double im_;
public:
    Complex();
    Complex(double re, double im);
    ~Complex() = default;
    bool operator <(const Complex& c) const;
    bool operator >(const Complex& c) const;
    bool operator <=(const Complex& c) const;
    bool operator >=(const Complex& c) const;
    double re() const;
    double im() const;
    double length() const;
};

Complex::Complex() : re_(0), im_(0) {}

Complex::Complex(double re, double im) : re_(re), im_(im) {}


double Complex::re() const {
    return re_;
}

double Complex::im() const {
    return im_;
}

double Complex::length() const {
    return sqrt(pow(this->re(), 2) + pow(this->im(), 2));;
}

bool Complex::operator<(const Complex &c) const {
    return length() < c.length();
}

bool Complex::operator>(const Complex &c) const {
    return length() > c.length();
}

bool Complex::operator>=(const Complex &c) const {
    return length() >= c.length();
}

bool Complex::operator<=(const Complex &c) const {
    return length() <= c.length();
}


#endif
