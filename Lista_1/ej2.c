#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define L 3

int cont (double x, double y, double z) ;
void randxyz(double * x, double * y, double * z) ;

int main (void) {
	int n, k, rep, i, j ;
	double x, y, z ;
	srand(time(NULL)) ;	

	printf("Introduce n, rep: ");
	scanf(" %d %d", &n, &rep) ;
	for (j = 0; j < rep; j++) {
		for (i = 0, k = 0; i < n; i++) {
			randxyz(&x, &y, &z) ;
			k += cont(x, y, z) ;
		}
		printf("k = %d V = %lf\n", k, L*L*L*( (double) k/n )) ;
	}
	

	return 0 ;
}

int cont (double x, double y, double z) {
	if (0 <= x && x <= 1 && y >= 0 && y <= 1 && z >= 0 && z <= 1) {
		if (x * x + sin(y) <= z && x - z + exp(y) <= 1) return 1;
	}
	return 0 ;
}

void randxyz (double * x, double * y, double * z) {
	*x = (double) rand() / RAND_MAX * L ;
	*y = (double) rand() / RAND_MAX * L ;
	*z = (double) rand() / RAND_MAX * L ;
	return ;
}
