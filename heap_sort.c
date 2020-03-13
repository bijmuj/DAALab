#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void maxheap(int h[], int n)
{
    int i, heap, v, j, k;
    for (i = n / 2; i > 0; i--)
    {
        k = i;
        v = h[k];
        heap = 0;
        while (!heap && (2 * k) <= n)
        {
            j = 2 * k;
            if (j < n)
                if (h[j] < h[j + 1])
                    j = j + 1;
            if (v >= h[j])
                heap = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heapsort(int h[], int n)
{
    int i, temp;
    if (n <= 1)
        return;
    else
    {
        maxheap(h, n);
        h[n] = h[1] + h[n] - (h[1] = h[n]);
        heapsort(h, n - 1);
    }
}

void main()
{
    int *h, n, i;
    double clk;
    clock_t start, end;
    //scanf("%d", &n);
    srand(clock());
    printf("n\truntime\n");
    for (n = 10; n <= 10000; n *= 10)
    {
        h = (int *)malloc(sizeof(int) * (n + 1));
        for (i = 1; i <= n; i++)
        {
            h[i] = rand() % (n * 10);
            // printf("%d\t", h[i]);
        }
        // printf("\n");

        start = clock();
        heapsort(h, n);
        end = clock();

        clk = (double)(end - start) / CLOCKS_PER_SEC;
        // for (i = 1; i <= n; i++)
        //     printf("%d\t", h[i]);

        printf("\n%d\t%lf\n", n, clk);
        free(h);
    }
}