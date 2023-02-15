#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void step(double xy[2]) ;

int main (void) {
	double xy[2] = { 0, 0 } ;
	int n, i ;

	scanf(" %d", &n) ;
	if (n < 1) return -1 ;
	
	printf("0 0 0\n") ;
	for (i = 1; i < n; i++) {
		step(xy) ;
		printf("%d %lf %lf\n", i, xy[0], xy[1]) ;
	}

	return 0 ;
}

void step(double xy[2]) {
	double ang;
	ang = (2 * M_PI * rand()) / RAND_MAX ;
	xy[0] += cos(ang) ;
	xy[1] += sin(ang) ;
	return ;
}
