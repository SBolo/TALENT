#include <iostream>
#include <stdio.h>
#include <stdlib.h>

double cacca(double *arrauz) {
    arrauz[0] = 1;
    
    return arrauz[0];
}

int main(int argc, char *argv[]) {
    
    double const pi = 3.14;
    double y;
    double x = (y = 3) * 4;
    double arrauz[5];
    
    std::cout << "Hello World\n";
    printf("Me ne frego di c++\n");
    
    printf("Non posso cambiare il valore di %g\n",pi);
    
    for (int i = 0; i < 10; i++) {
        printf("%g\n",cacca(arrauz));
    }
    
    
    return 0;
}
