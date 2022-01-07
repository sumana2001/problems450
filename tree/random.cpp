#include <iostream>
using namespace std ;
// creating a generic function ‘swap (parameter-list)’ using template :
template <class X> 
void Swap( X &a, X &b) {
    X tp;
    tp = a;
    a = b;
    b = tp;
    cout << " Swapped elements values of a and b are  " << a << " and  " << b << " respectively " << endl;
}

int main( ) {
    int a = 10, b = 20 ;
    float c = 10.5, d = 20.5 ;
    Swap(a , b);          // function swapping ‘int’ elements 
    Swap(c , d);                  // function swapping ‘float’ elements 
    return 0;
}