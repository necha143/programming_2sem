#include "laba.cuh"

void test_comp(){

    Complex a = Complex( 2, 3 );
    Complex b = Complex( 5, 7 );
    Complex c = Complex( 6, 9 ); int numb=5;
    Complex d = Complex( 5, 5); int length=0;
    c=c*numb; c.Display();
    a+=b; a.Display();
    b+=a; b.Display();
    length=d^d; cout << length << "\n";

}

void test_queue(){

    vector <int> arrrr;
    Queue a = Queue(0, arrrr);
    Queue b = Queue(5,arrrr);
    Queue c = Queue(5, arrrr);
    Queue d = Queue(6, arrrr);
    a=a<<b; a.Display();
    a=a<<d; a.Display();
    a=a>>c; a.Display();

}


int main(){
    test_comp();
    test_queue();
    return 0;
}