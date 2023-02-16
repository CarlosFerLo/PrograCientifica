#include <stdio.h>
#include <math.h>

#define DIM 20
#define H 1e-2
#define EPSILON 1e-6
#define ITER_MAX 100

double p(double a[DIM], int n, double x) ;
double dp(double a[DIM], int n, double x) ;
double cauchy(double a[DIM], int n) ;
int nr(double a[DIM], int n, double *x) ;

int main(void) {
	int n, i ;
	double c, l, x, a[DIM] ;

	scanf(" %d", &n) ;
	if (n < 1 || n > DIM) return 1 ;
	
	for (i = 0; i <= n; i++) scanf(" %lf", &a[i]) ;
	printf("Raices:\n") ;
	c = cauchy(a, n) ;
	
	for (l = -c; l < c; l += H) {
		if (p(a, n, l) * p(a, n, l+H) <= 0) {
			x = l + H/2 ;
			switch (nr(a, n, &x)) {
				case 0: 
					printf("%lf\n", x) ;
					break ;
				case 1:
					printf("ERROR DE CONVERGENCIA\n") ;
					break ;
				case 2:
					printf("DIVISION POR 0\n") ;
					break ;
			}
		}
	}

	return 0 ;
}

double cauchy (double a[DIM], int n) {
	double max, aux ;
	int i ;
	max = fabs(a[0]/a[n]) ;
	for (i = 1; i < n; i++) {
		aux = fabs(a[i]/a[n]) ;
		if (aux > max) max = aux ;	
	}
	return 1 + max ;
}

double p (double a[DIM], int n, double x) {
	int i ;
	double b ;
	b = a[n] ;
	for (i = n - 1; i >= 0; i--) {
		b = a[i] + b * x ;
	}
	return b ;
}

double dp (double a[DIM], int n, double x) {
	int i ;
	double b ;
	b = a[n] * n ;
	for (i = n - 1; i > 0; i--) {
		b = a[i] * i + b * x ;
	}
	return b ;
}

int nr (double a[DIM], int n, double *x) {
	int i ;
	double aux ;
	aux = *x ;
	for (i = 0; i < ITER_MAX; i++) {
		if (dp(a, n, *x) == 0) return 2 ;
		*x = *x - (p(a, n, *x) / dp(a, n, *x)) ;
		if (fabs(aux - *x) < EPSILON) return 0 ;
		aux = *x ;	
	}
	return 1 ;
}




