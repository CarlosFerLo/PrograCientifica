#include <stdio.h>

void mcd_mcm(int *n, int *m) ;

int main (void) {
	int n, m ;

	scanf(" %d, %d", &n, &m) ;
	if (n <= 0 || m <= 0) return 1 ;

	mcd_mcm(&n, &m) ;

	printf("mcd: %d, mcm: %d\n", n, m) ;

	return 0 ;
}

void mcd_mcm(int *n, int *m) {
	int x, y, r ;

	if (*n > *m) {
		x = *n ;
		y = *m ;
	} else {
		x = *m ;
		y = *n ;
	}
	
	do {
		r = x % y ;
		x = y ;
		y = r ;
	} while (r != 0) ;

	*m = (*m) * (*n)/x ;
	*n = x ;

	return ;
}
