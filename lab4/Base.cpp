#include "Base.h"

using namespace std;

CVector2D::CVector2D() : x(0), y(0) {
    double x = 0, y = 0;
}

istream &operator>>(istream &in, CVector2D &vector) {
    in >> vector.x >> vector.y;
    return in;
}

ostream &operator<<(ostream &out, const CVector2D &vector) {
    out << "(" << vector.x << ";" << vector.y << ")";
    return out;
}