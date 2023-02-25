#ifndef LAB1_LABA_CUH
#define LAB1_LABA_CUH
#include <iostream>
#include <complex>
#include <array>

using namespace std;

void Plus_ind(int *a, int *b);
void Plus_link(int &a, int &b);
void check_plus(int a, int b);

void Change_ind(int *a);
void Change_link(int &a);
void check_change(int a);

void Komplex_ind(complex <double> *a);
void Komplex_link(complex <double> &a);
void check_komplex(double x, double i);

void Matrix_ind(int (*a)[3], double *ch);
void Matrix_link(int (&a)[3][3], double &ch);
void check_matrix(int ch, double b);

#endif //LAB1_LABA_CUH