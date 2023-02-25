#include "laba.cuh"

void Plus_ind(int *a, int *b){
    *a+=*b;
}

void Plus_link(int &a, int &b){
    a+=b;
}

void check_plus(int a, int b){
    int *c=&a; int *d=&b;
    int &e=a; int &f=b;
    const int help1 = a+b;
    const int help2 = *c+*d;
    const int help3 = e+f;
    
    if (help1==help2){
        if (help1==help3) {
            cout << "Plus is correct";
        }
    } else {
        cout << "Plus is incorrect";
    }
}


void Change_ind(int *a){
    //int sign = *a < 0? -1:1;
    *a*=-1;
}

void Change_link(int &a){
    //int sign = a < 0? -1:1;
    a*=-1;
}

void check_change(int a){
    int *b=&a; int &c=a;
    if (a*-1 == *b*-1){
        if (a*-1 == c*-1){
            cout << "\n" << "Change is correct";
        }
    } else {
        cout << "Change is incorrect";
    }
}


void Komplex_ind(complex <double> *a){
    complex <double> sec (a->real(), -1*(a->imag())); // также можно использовать просто conj()
    *a=sec;                                                // (возвращает сопряженное комплексное число x)
}

void Komplex_link(complex <double> &a){
    complex <double> sec (a.real(), -1*(a.imag()));
    a=sec;
}

void check_komplex(double x, double i){
    complex <double> a (x, i);
    complex <double> *b=&a;
    complex <double> &c=a;
    complex <double> sec_a (a.real(), -1*a.imag());
    complex <double> sec_b (b->real(), -1*b->imag());
    complex <double> sec_c (c.real(), -1*c.imag());
    if (sec_a==sec_b){
        if (sec_a==sec_c){
            cout << "\n" << "Komplex is correct";
        }
    } else {
        cout << "Komplex is correct";
    }
}


void Matrix_ind(int (*a)[3], double *ch) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] *= *ch;
        }
    }
}

void Matrix_link(int (&a)[3][3], double &ch) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] *= ch;
        }
    }
}

void check_matrix(int ch, double b) {
    //array<array<int, 3>, 3> a;
    int arr[3][3];  int arr_help[3][3];  int arr_help2[3][3];
    int (*arr1)[3] = arr_help;  double *b1=&b;
    int (&arr2)[3][3]=arr_help2; double &b2=b;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = ch;
            arr_help[i][j]=ch;
            arr_help2[i][j]=ch;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] *= b;
        }
    }

     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             arr1[i][j] *= *b1;
         }
     }

     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             arr2[i][j] *= b2;
         }
     }                                     


     bool check = true;
     for (int i=0; i<3; i++){
         for (int j=0; j<3; j++){
             if (arr[i][j] != arr1[i][j]) {
                 if (arr[i][j] != arr2[i][j]){
                     check = false;
                     break;
                 }
             }
         }
     }
     if (check){
         cout << "\n" << "Matrix is correct";
     } else {
         cout << "Matrix in incorrect";
     }

}

int main(){
    check_plus(2,3);
    check_change(3);
    check_komplex(2,3);
    check_matrix(1,2);
    return 0;
}