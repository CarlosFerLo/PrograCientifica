#include <stdio.h>
#include <math.h>

double f(double x) ;

int main(void) {
	int n, i ;
	double h, a, b, sum ;

	printf("# introduce a, b y n: ");
	scanf(" %lf %lf %d", &a, &b, &n);
	h = (b - a) / n ;

	for (i = 1, sum = 0; i < n; i++) sum += f(a + i * h) ;

	printf("Resultado: %lf\n", (h/2) * (f(a) + 2 * sum + f(b))) ;
	return 0 ;
}

double f(double x) {
	if (x > 0 && x < 1) 
		return log(x) * log(1 - x) ;
	else 
		return 0 ;
}
