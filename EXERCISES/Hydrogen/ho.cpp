#include <stdio.h>
#include <math.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_sf_laguerre.h>

#define RMAX 10.
#define L(n,a,x)  gsl_sf_laguerre_n(n,a,x)
#define FACT(n) gsl_sf_fact(n) //vuole un unsigned int: fattoriale - ritorna double
#define SFACT(n) gsl_sf_doublefact(n) //di nuovo unsigned: semifattoriale - ritorna double


typedef struct {
    int n;
    double *norm;
    int dim;
    double b; //parameter in the normalization, which is variational
    int l; //angular momentum eigenvalue
} prms;


/*__________________________________________________FUNCTIONS_FOR_ANALYSIS________________________________________________*/
double qgauss(double (*func)(double), double a, double b) { //Gauss quadrature algorithm for integration
    
    int j;
    double xr, xm, dx, s;
    static float x[] = {0.0, 0.1488743389, 0.4333953941, 0.6794095682, 0.8650633666, 0.9739065285};
    static float w[] = {0.0, 0.2955242247, 0.2692667193, 0.2190863625, 0.1494513491, 0.0666713443};
    
    xm = 0.5 * (b + a);
    xr = 0.5 * (b - a);
    s = 0;
    
    for (j=1;j<=5;j++) {
        dx = xr * x[j];
        s += w[j] * ( (*func)(xm + dx) + (*func)(xm-dx) );
    }
    
    return s *= xr;
}
/*______________________________________________________END_ANALYSIS____________________________________________________*/


double basis(double x, void *params) { //Base dell'oscillatore armonico 3D
    
    prms *P = (prms *)params;
    int n = P->n;
    double j = P->norm[n];
    double b = pow(P->b, 3./2.);
    int l = P->l;
    
    return (j/b) * exp(-x*x/2.) * pow(x,l) * L(n, 1./2. + l, x*x);
}


int main() {
    
    double x, integ, integ2, energy, energy_old;
    unsigned int i;
    double norm[101];
    int j;
    FILE *pt;
    
    gsl_function F, V;
    prms P;
    
    double *psi = (double *)malloc((RMAX/STP) * sizeof(double)); //funzione d'onda
    
    F.function = basis;
    F.params = &P;
    V.function = potential;
    V.params = NULL;
    P.norm = norm;
    P.l = 0.;
    
    for( i = 0; i <= 100; i++ ) {
        norm[i] = sqrt( pow(2.,i + P.l +2) * FACT(i) / ( sqrt(M_PI) * SFACT(2*i + 2*P.l + 1) ) ); //coefficienti di normalizzazione della base
    }
    
    printf("Normalization: %g\n", qgauss)
    
    return 0;
}
