#include <stdio.h>
#include <time.h>

int a[10][10], visited[10], n, cost=0;


int least(int c){
    int i, nc=999, min=999;
    for (i=0; i< n; i++){
        if (a[c][i] && visited[i]==0){
            if (a[c][i]<min){
                min=a[c][i];
                nc=i;
            } 
        }
    }
    if (min !=999)
        cost+=min;
    return nc;
}

void mincost(int city){
    int i, ncity;
    visited[city]=1;
    printf("%d-->", city+1);
    ncity=least(city);
    if(ncity==999){
        ncity=0;
        printf("1");
        cost+=a[city][ncity];
        return;
    }
    mincost(ncity);
}

void main(){
    int i, j;
    double clk; 
    clock_t start, end;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            scanf("%d", &a[i][j]);
            a[j][i]=a[i][j];
        }
        visited[i]=0;
        a[i][i]=0;
    }
    for (i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    start=clock();
    mincost(0);
    end=clock();
    printf("cost=%d\n", cost);

}