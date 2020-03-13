#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int *a, int low, int high)
{
	int i, j, pivot;
	pivot = a[low];
	while (i < j)
	{
		for (i = low + 1; i < high && a[i] <= pivot; i++)
			;
		for (j = high; a[j] > pivot; j--)
			;

		if (i < j)
			a[j] = a[i] + a[j] - (a[i] = a[j]);
		else
		{
			a[j] = a[low] + a[j] - (a[low] = a[j]);
			return j;
		}
	}
}

void quick_sort(int *a, int low, int high)
{
	if (low < high)
	{
		int j = partition(a, low, high);
		quick_sort(a, low, j - 1);
		quick_sort(a, j + 1, high);
	}
}

void main()
{
	int i, n, *a;
	double clk;
	clock_t start, end;
	srand(time(0));
	printf("n\truntime\n");
	for (n = 10; n <= 100000; n *= 10)
	{
		a = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i++)
		{
			// a[i] = rand() % (n * 10);
			a[i] = n - i;
			// printf("%d\t", a[i]);
		}
		// printf("\n");
		start = clock();
		quick_sort(a, 0, n - 1);
		end = clock();
		clk = (double)(end - start) / CLOCKS_PER_SEC;
		// for (i = 0; i < n; i++)
		// 	printf("%d\t", a[i]);
		printf("\n%d\t%lf\n", n, clk);
		free(a);
	}
}