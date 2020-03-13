#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	clock_t start, end;
	double clk; 
	int n, top, count, visiting, i, j;
	scanf("%d", &n);
	int stack[n], visited[n], a[n][n];
	for (i=0; i<n; i++){
		a[i][i]=2;
		for(j=i+1; j<n; j++){
			a[j][i]=a[i][j]=(rand()%2);
		}
		visited[i]=0;
	}
	/*
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	*/
	start=clock();
	count=1;
	top=0;
	stack[top]=0;
	while(count<=n && top!=-1){
		//current node
		visiting=stack[top--];
		// updating visited list and popping stack
		visited[visiting]=count++;
		//adding children of current node
		for (i=0; i<n; i++){	
			if (a[visiting][i]==0 && visited[i]==0){
				//if adjacent push to stack
				top++;
				stack[top]=i;
			}
		}
	}
	end=clock();
	/*
	printf("node\torder of visit\n");
	for (i=0; i<n; i++){
		printf("%d\t%d\n", i, visited[i]);
	}*/
	clk=(double)(end-start)/CLOCKS_PER_SEC;
	printf("runtime=%lf\n", clk);
}
	
				
		
	
