#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum Commands {
    ADD = 1,
    SHOW,
    SUM_AREAS,
    SUM_PERIMETERS,
    CENTRE_MASS,
    MEMORY,
    SORT,
    EXIT
};

enum Figures {
    SEGMENT = 1,
    TRAPEZOID = 2,
};


class IGeoFig {
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x;
    double y;

    CVector2D();

    friend istream &
    operator>>(istream &, CVector2D &); // friend - функция, которая не вляется членом класса, но имеет доступ к private
    friend ostream &operator<<(ostream &, const CVector2D &);
};

class IPhysObject {
public:
    virtual double mass() const = 0;

    virtual CVector2D position() const = 0;

    virtual bool operator==(const IPhysObject &obj) const = 0;

    virtual bool operator<(const IPhysObject &obj) const = 0;

};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogueInitiable {
public:
    virtual void initFromDialogue() = 0;
};

class BaseCObject {
public:
    virtual const char *className() = 0;

    virtual unsigned int size() = 0;
};

class IFigure
        : public IGeoFig,
          public IPhysObject,
          public IPrintable,
          public IDialogueInitiable,
          public BaseCObject,
          public CVector2D {
};