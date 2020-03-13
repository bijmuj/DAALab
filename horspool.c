#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_table(int *t, char *key, int n)
{
    int i;
    for (i = 0; i < 256; i++)
        t[i] = n;
    for (i = 0; i < n - 1; i++)
        t[(int)key[i]] = n - 1 - i;
}

int horspool(int *t, char *key, char *source, int m, int n)
{
    int i, j;
    for (i = n - 1; i < m;)
    {
        for (j = 0; source[i - j] == key[n - 1 - j] && j < n; j++)
            ;
        if (j == n)
            return i - j + 1;
        else
            i += t[(int)source[i]];
    }
    return -1;
}

void main()
{
    int n, m;
    double clk;
    clock_t start, end;
    scanf("%d %d", &m, &n);
    char key[n], source[m];
    scanf("%s", source);
    scanf("%s", key);
    int t[256];
    fill_table(t, key, n);
    start = clock();
    printf("%d", horspool(t, key, source, m, n));
    end = clock();
    clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nruntime=%lf\n", clk);
}