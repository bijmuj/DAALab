#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, j, n, temp, last;
    int *a;
    double clk;
    clock_t start, end;
    srand(time(0));
    printf("n\truntime\n");
    for (n = 10; n <= 10000; n *= 10)
    {
        a = (int *)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++)
            a[i] = rand() % (n * 10);
        start = clock();
        for (i = 1; i < n; i++)
        {
            temp = a[i];
            last = i;
            for (j = i - 1; j >= 0; j--)
            {
                if (temp < a[j])
                    last = j;
            }
            for (j = i; j > last; j--)
                a[j] = a[j - 1];
            a[last] = temp;
        }
        end = clock();
        // for (i=0; i<n; i++)
        //     printf("%d\t", a[i]);
        // printf("\n");
        clk = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%lf\n", n, clk);
        free(a);
    }
}