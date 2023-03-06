#include "Segment.h"

Segment::~Segment()=default;

Segment::Segment() {
    this->Segment::initFromDialogue();
}

void Segment::initFromDialogue() {
    cout << "Add first coords: ";
    cin >> A;
    cout << endl;
    cout << "Add second coords: ";
    cin >> B;
    cout << endl;
    cout << "Add weight: ";
    cin >> weight;
    cout << endl;
}

double Segment::square() {
    return 0;
}

double
Segment::perimeter() { // так как отрезок - одномерная фигура, то у неё не может быть как площади, так и периметра
    return 0;
}

double Segment::mass() const {
    return weight;
}

CVector2D Segment::position() const {
    CVector2D center;
    center.x = (A.x + B.x) / 2;
    center.y = (A.y + B.y) / 2;
    return center;
}

bool Segment::operator==(const IPhysObject &object) const {
    return mass() == object.mass();
}

bool Segment::operator<(const IPhysObject &object) const {
    return mass() < object.mass();
}

void Segment::draw() {
    cout << "Name: " << name << endl;
    cout << "Position: " << position() << endl;
    cout << "Weight: " << weight << endl;
    cout << "Size: " << size() << endl;
    cout << endl;
}

const char *Segment::className() {
    return name;
}

unsigned Segment::size() {
    return sizeof(*this);
}
