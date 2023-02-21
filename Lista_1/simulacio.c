#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100000
#define DIM 1000

int includes (int x, int pos, int hist[DIM]) ; 

int main (void) {
	int n, cont, i, j, hist[DIM] ;
	srand(time(NULL)) ;

	scanf(" %d", &n) ;
	if (n < 1 || n > DIM) return -1 ;

	for (i = 0, cont = 0; i < M; i++) {
		for (j = 0; j < n; j++) {
			hist[j] = rand() % 365 + 1 ;
			if (includes(hist[j], j, hist)) {
				cont += 1 ;
				break ;
			} 
		}
	}

	printf("Prob: %lf\n", (double) cont / M) ;

	return 0 ;
}

int includes (int x, int pos, int hist[DIM]) {
	int i;
	for (i = 0; i < pos; i++) {
		if (hist[i] == x) return 1 ;
	}
	return 0 ;
}
