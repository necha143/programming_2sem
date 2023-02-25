#include "laba.cuh"

Complex Complex::operator+=(const Complex &b) {
    re += b.re;
    im += b.im;
    return *this;
}

Complex Complex::operator*(const int &b) {
    re *= b;
    im *= b;
    return *this;
}

double Complex::operator^(Complex a) { // длина комплексного числа
    double length = pow(re * re + im * im, 0.5);
    return length;
}

Complex Complex::operator*=(const Complex &b) {
    re = re * b.re - im * b.im;
    im = re * b.im + im * b.re;
    return *this;
}


Queue Queue::operator<<(Queue &neww) {
    arr.push_back(neww.numb);
    return Queue(neww.numb, arr);
}

Queue Queue::operator>>(Queue &del) {
    for (int i = 0; i < arr.size(); i++) {
        if (del.numb == arr[i]) {
            swap(arr[i], arr[arr.size() - 1]);
        }
    }

    bool check = false;
    for (int i = 0; i < arr.size(); i++) {
        if (del.numb == arr[i]) {
            check = true;
        }
    }
    if (check == false) {
        cout << "\n" << "There aren't such number in queue";
        return Queue(del.numb, arr);
    }

    del.numb = arr[arr.size() - 1];
    arr.pop_back();
    return Queue(del.numb, arr);
}