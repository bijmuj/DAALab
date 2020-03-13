#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	int i, j, n, t;
	double clk;
	clock_t start, end;

	int *a;
	srand(time(0));
	for (n=10; n<=10000; n*=10){
		a=(int *)malloc(sizeof(int)*n);
		for (i=0; i<n; i++){
			a[i]=rand()%(n*10);
		}
		printf("\n");
		start=clock();
		for (i=0; i<n-1; i++){
			for(j=0; j<n-1-i; j++){
				if (a[j]>a[j+1]){
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		end=clock();

		clk=(double)(end-start)/CLOCKS_PER_SEC;
		printf("\nn\truntime\n%d\t%lf\n", n, clk);
		free(a);
	}
}
	

