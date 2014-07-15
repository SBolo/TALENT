#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "armadillo"

using namespace arma;
using namespace std;

int main(int argc, char *argv[]) {
    
    mat A (5,5);
    A(1,1) = 3.;
    //mat B(5,5,fill::eye);
    mat B = eye<mat>(5,5); //altro modo di dichiarare l'identità 5x5
    
    vec x(5);
    rowvec y(5);
    
    for(int i = 0; i < 5; i++) {
        x(i) = i+1;
        y(i) = i-2;
        //printf("%g\n",x(i));
    }
    
    vec C = B*x;
    
    C.print();
    
    if( C.is_vec() ) {
        cout << "Good!\n";
    }
    rowvec D = y*B;
    
    for(int i=0; i <5; i++) {
            printf("C(%d) = %g, D(i) = %g\n",i,C(i),D(i));
    }
    
    cout << "The maximum value in C is " << C.max() << endl;
    cout << "The minimum value in C is " << C.min() << endl;
    
    mat X = randi<mat>(5,5, distr_param(-1,10));
    
    X.print(); //WHAT THE ACTUAL FUCK? 
    cout << "X has " << X.n_cols << " columns" << endl;
    cout << "X has " << X.n_rows << " rows" << endl;
    cout << "detX = " << det(X) << endl;
    
    mat Z = X.i();
    
    Z.print();
    
    mat H(2,2);
    
    H << 1 << 2 << endr
      << 3 << 4 << endr;
    
    cout << H(1,1) << endl;
    
    mat G = randu<mat>(10,10);
    
    if( G.is_square() ) {
        cout << "G is a square matrix\n";
           mat F = G.i(); //inverse of G 
    }
    
    return 0;
}
