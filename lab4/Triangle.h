#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H

#include "interfaces.h"

class Triangle : public IFigure {
public:
    Triangle();
    virtual ~Triangle();
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() const override;
    bool operator==(const IPhysObject& obj) const override;
    bool operator<(const IPhysObject& obj) const override;
    void draw() override;
    void initFromDialogue() override;
    const char* className() override;
    unsigned int size() override;
private:
    CVector2D A;
    CVector2D B;
    CVector2D C;
    double weight = 0;
    const char* name = "Triangle";
};


#endif //LAB1_TRIANGLE_H
