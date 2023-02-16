#include <stdio.h>

double S1 (int N) ;
double S2 (int N) ;

int main (void) {
	int N[] = { 1e3, 1e4, 1e5, 1e6 }, i, j ;
	float f_sum ;
	double d_sum ;
	for (i = 0; i < 4; i++) {
		printf("# Caso N = %d\n", N[i]) ;
		printf("## float | 1 -> N\n") ;
		for (j = 1, f_sum = 0; j <= N[i]; j++) f_sum += 1. / (j * j) ;
		printf("S(N) = %.10f\n", f_sum) ;  
		printf("## float | N -> 1\n") ;
		for (j = N[i], f_sum = 0; j > 0; j--) f_sum += 1. / (j * j) ;
		printf("S(N) = %.10f\n", f_sum) ;  
		printf("## double | 1 -> N\n") ;
		for (j = 1, d_sum = 0; j <= N[i]; j++) d_sum += 1. / (j * j) ;
		printf("S(N) = %.10lf\n", d_sum) ;
		printf("## double | N -> 1\n") ;
		for (j = N[i], d_sum = 0; j > 0; j--) d_sum += 1. / (j * j) ;
		printf("S(N) = %.10lf\n", d_sum) ;  
	}
	return 0 ;
}

