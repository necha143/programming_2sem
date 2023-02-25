#ifndef LABA3_LABA_CUH
#define LABA3_LABA_CUH
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


class Complex {
    double re = 0.0;
    double im = 0.0;
public:
    Complex(double re, double im): re(re), im(im) {}
    Complex() {}

    Complex operator+=(const Complex& b);

    Complex operator*(const int& b);

    double operator^(Complex a);

    Complex operator*=(const Complex& b);

    void Display(){ cout << re << " " << im << "\n";}
};



class Queue{ // работа с очередью на векторе
    vector<int> arr; int numb;
public:
    Queue(int num, vector<int> array) : numb(num), arr(array) {}
    Queue operator<<( Queue &neww);
    Queue operator>> (Queue &del);

    void Display( ) {
        int help=-1;
        for (int i=0; i<arr.size(); i++){
            cout << arr[i] << " ";
            help=i;
        }
        cout << "\n";
        if (help==-1){
            cout << "No elements in queue";
        }
    }
};


#endif //LABA3_LABA_CUH