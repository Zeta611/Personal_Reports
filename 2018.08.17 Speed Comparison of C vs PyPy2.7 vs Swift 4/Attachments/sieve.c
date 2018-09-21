#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sieve_eratosthenes(unsigned int n)
{
	int *sieve = calloc(n, sizeof(unsigned int));
	sieve[0] = 1;
	for (int p = 2; p <= n; ++p) {
		if (sieve[p - 1] == 0) {
			/* printf("%d\n", p); */
			for (int i = p * p; i <= n; i += p)
				sieve[i - 1] = 1;
		}
	}
}

int main(void)
{
	unsigned int n = 100000000;
	double average = 0.0;
	for (int i = 0; i < 100; i++) {
		clock_t start = clock();
		sieve_eratosthenes(n);
		clock_t end = clock();
		average += (double) (end - start) / CLOCKS_PER_SEC;
	}
	printf("%f\n", average / 100.);
	return 0;
}

