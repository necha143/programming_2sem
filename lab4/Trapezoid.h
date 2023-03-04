#pragma once

#include "Base.h"
#include <iostream>
#include <math.h>

using namespace std;

class Trapezoid : public IFigure {
private:
    CVector2D A;
    CVector2D B;
    CVector2D C;
    CVector2D D;
    double weight = 0;
    const char *name = "Trapezoid";
public:
    Trapezoid();

    ~Trapezoid();

    double square() override;

    double perimeter() override;

    double mass() const override;

    CVector2D position() const override;

    bool operator==(const IPhysObject &obj) const override;

    bool operator<(const IPhysObject &obj) const override;

    void draw() override;

    void initFromDialogue() override;

    const char *className() override;

    unsigned int size() override;
};