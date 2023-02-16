#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 590

void generate (int n, double A[N][N]) ;
void printMat(int n, double A[N][N]) ;

int main (void) {
	int n, i, j, k ;
	double A[N][N], B[N][N], C[N][N] ;
	clock_t start, end ;
	srand(time(NULL)) ;

	printf("Introduce n: ") ;
	scanf(" %d", &n) ;
	if (n < 1 || n > N) return 1 ;

	generate(n, A) ;
	generate(n, B) ;

	printf("A =\n") ;
	printMat(n, A) ;
	printf("B =\n") ;
	printMat(n, B) ;

	/* Iter 1: i j k */
	start = clock() ;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0 ;
			for (k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j] ;
		}
	}
	end = clock() ;

	printf("Result:\n") ;
	printMat(n, C) ;
	printf("Time: %.10lf\n\n", (double) (end - start) / CLOCKS_PER_SEC) ;
	
	/* Iter 2: i k j */
	start = clock() ;
	for (i = 0; i < n; i++) {
		for (k = 0; k < n; k++) {
			for (j = 0; j < n; j++) {
				if (k == 0) C[i][j] = A[i][k] * B[k][j] ;
				else C[i][j] += A[i][k] * B[k][j] ;
			}
		}
	}
	end = clock() ;

	printf("Result:\n") ;
	printMat(n, C) ;
	printf("Time: %.10lf\n\n", (double) (end - start) / CLOCKS_PER_SEC) ;

	/* Iter 3: j i k */
	start = clock() ;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			C[i][j] = 0 ;
			for (k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j] ;
		}
	}
	end = clock() ;

	printf("Result:\n") ;
	printMat(n, C) ;
	printf("Time: %.10lf\n\n", (double) (end - start) / CLOCKS_PER_SEC) ;
	
	/* Iter 4: j k i */
	start = clock() ;
	for (j = 0; j < n; j++) {
		for (k = 0; k < n; k++) {
			for (i = 0; i < n; i++) {
				if (k == 0) C[i][j] = A[i][j] * B[i][j] ;
				else C[i][j] += A[i][k] * B[k][j] ;
			}
		}
	}
	end = clock() ;

	printf("Result:\n") ;
	printMat(n, C) ;
	printf("Time: %.10lf\n\n", (double) (end - start) / CLOCKS_PER_SEC) ;
	
	/* Iter 5: k i j */
	start = clock() ;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (k == 0) C[i][j] = A[i][k] * B[k][j] ;
				else C[i][j] += A[i][k] * B[k][j] ;
			}
		}
	}
	end = clock() ;

	printf("Result:\n") ;
	printMat(n, C) ;
	printf("Time: %.10lf\n\n", (double) (end - start) / CLOCKS_PER_SEC) ;
	
	/* Iter 6: k j i */
	start = clock() ;
	for (k = 0; k < n; k++) {
		for (j = 0; j < n; j++) {
			for (i = 0; i < n; i++) {
				if (k == 0) C[i][j] = A[i][k] * B[k][j] ;
				else  C[i][j] += A[i][k] * B[k][j] ;
			}
		}
	}
	end = clock() ;

	printf("Result:\n") ;
	printMat(n, C) ;
	printf("Time: %.10lf\n\n", (double) (end - start) / CLOCKS_PER_SEC) ;
	
	return 0 ;
}

void generate (int n, double A[N][N]) {
	int i, j;

	for(i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = ( (double) rand() / RAND_MAX ) * 2. - 1;
		}
	}
	return ;
}

void printMat(int n, double A[N][N]) {
	int i, j ;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) printf(" %lf", A[i][j]) ;
		printf("\n") ;
	}
}
