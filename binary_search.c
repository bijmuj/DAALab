#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int n, i, j, t, l, h, m, k, f = 0;
	double clk;
	clock_t start, end;

	int *a;
	srand(time(0));
	for (n = 10; n <= 10000; n *= 10)
	{
		a = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i++)
			a[i] = rand() % (n);

		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - 1 - i; j++)
			{
				if (a[j] > a[j + 1])
				{
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
		k = rand() % (n);
		h = n;
		l = 0;
		f = 0;
		start = clock();
		while ((h - l) > 1)
		{
			m = (h + l) / 2;
			if (a[m] == k)
			{
				f = 1;
				break;
			}
			if (a[m] > k)
				h = m;
			else
				l = m;
		}
		end = clock();
		if (f)
			printf("key found at:%d", m);
		else
			printf("key not found");

		clk = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\nn\truntime\n%d\t%lf\n", n, clk);
		free(a);
	}
}
