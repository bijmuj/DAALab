#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void warshall(int **a, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (a[i][j] || (a[i][k] && a[k][j]))
                    a[i][j] = 1;
}

void main()
{
    int n, i, j;
    double clk;
    clock_t start, end;
    srand(clock());
    // scanf("%d", &n);
    printf("n\truntime\n");
    for (n = 5; n < 25; n += 5)
    {
        int **a;
        a = (int **)malloc(sizeof(int *) * n);
        for (i = 0; i < n; i++)
        {
            a[i] = (int *)malloc(sizeof(int) * n);
            for (j = 0; j < n; j++)
            {
                // scanf("%d", &a[i][j]);
                a[i][j] = rand() % 2;
                // printf("%d\t", a[i][j]);
            }
            // printf("\n");
        }
        start = clock();
        warshall(a, n);
        end = clock();
        // printf("closure matrix:\n");
        // for (i = 0; i < n; i++)
        // {
        //     for (j = 0; j < n; j++)
        //         printf("%d\t", a[i][j]);
        //     printf("\n");
        // }
        clk = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%lf\n", n, clk);
        free(a);
    }
}
