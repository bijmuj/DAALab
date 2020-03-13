#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	int n, qf, ql, count, visiting, i, j;
	scanf("%d", &n);
	srand(time(0));
	int q[n], visited[n], a[n][n];
	for (i=0; i<n; i++){
		a[i][i]=2;
		for(j=i+1; j<n; j++)
			a[j][i]=a[i][j]=rand()%2;
		visited[i]=0;
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	count=1;
	qf=0;
	ql=0;
	q[qf]=0;
	while(count<=n && ql>=qf){
		//current node
		visiting=q[qf++];
		// updating visited list and dequeueing
		visited[visiting]=count++;
		//adding children of current node
		for (i=0; i<n; i++){	
			if (a[visiting][i]==0 && visited[i]==0){
				//if adjacent enqueue
				ql++;
				q[ql]=i;
			}
		}
	}
	
	printf("node\torder of visit\n");
	for (i=0; i<n; i++){
		printf("%d\t%d\n", i, visited[i]);
	}
	
}			
