#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int pertenece(double x, double y, double z) ;

int main (void) {
	int n, i, cont ;
	double x, y, z ;
	srand(time(NULL)) ;

	scanf(" %d", &n) ;
	
	for (i = 0, cont = 0; i < n; i++) {
		x = rand() / RAND_MAX ;
		y = rand() / RAND_MAX ;
		z = rand() / RAND_MAX ;

		if (pertenece(x, y, z) == 1) cont++ ;
	}

	printf("Volumen: %lf\n", (1. * cont) / n);

	return 0 ;
}

int pertenece(double x, double y, double z) {
	if (x*x + sin(y) <= z && x - z + exp(y) <= 1)
		return 1;
	else
		return 0; 
}
