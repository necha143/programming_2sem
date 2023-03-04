#include "Trapezoid.h"


Trapezoid::Trapezoid() {
    this->Trapezoid::initFromDialogue();
}

void Trapezoid::initFromDialogue() {
    cout << "Add first coords: ";
    cin >> A;
    cout << endl;
    cout << "Add second coords: ";
    cin >> B;
    cout << endl;
    cout << "Add third coords: ";
    cin >> C;
    cout << endl;
    cout << "Add fourth coords: ";
    cin >> D;
    cout << endl;
    cout << "Add weight: ";
    cin >> weight;
    cout << endl;
}

double Trapezoid::square() {
    return ((B.x - A.x) * (A.y + B.y)) / 2 + ((C.x - B.x) * (B.y + C.y)) / 2 + ((D.x - C.x) * (C.y + D.y)) / 2 +
           ((A.x - D.x) * (D.y + A.y)) / 2;
}

double Trapezoid::perimeter() {
    double AB, BC, CD, DA;
    AB = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    BC = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    CD = sqrt((C.x - D.x) * (C.x - D.x) + (C.y - D.y) * (C.y - D.y));
    DA = sqrt((D.x - A.x) * (D.x - A.x) + (D.y - A.y) * (D.y - A.y));
    return (AB + BC + CD + DA) / 2;
}

double Trapezoid::mass() const {
    return weight;
}

CVector2D Trapezoid::position() const {
    CVector2D center;
    center.x = (A.x + B.x + C.x + D.x) / 4;
    center.y = (A.y + B.y + C.y + D.y) / 4;
    return center;
}

bool Trapezoid::operator==(const IPhysObject &object) const {
    return mass() == object.mass();
}

bool Trapezoid::operator<(const IPhysObject &object) const {
    return mass() < object.mass();
}

void Trapezoid::draw() {
    cout << "Name: " << name << endl;
    cout << "Position: " << position() << endl;
    cout << "Weight: " << weight << endl;
    cout << "Size: " << size() << endl;
    cout << endl;
}

const char *Trapezoid::className() {
    return name;
}

unsigned Trapezoid::size() {
    return sizeof(*this);
}