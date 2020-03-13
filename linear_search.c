#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, n, k;
	double clk;
	clock_t start, end;
	int *a;
	srand(time(0));
	for (n = 10; n <= 100000; n *= 10)
	{
		a = (int *)malloc(sizeof(int) * (n + 1));
		for (i = 0; i < n; i++)
			a[i] = rand() % (n * 10);
		i = 0;
		a[n] = rand() % (n * 10);
		start = clock();
		while (a[i] != a[n])
		{
			i++;
		}
		end = clock();

		if (i != n)
			printf("key found at:%d", i);
		else
			printf("key not found");

		clk = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\nn\truntime\n%d\t%lf\n", n, clk);
		free(a);
	}
}
