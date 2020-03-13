#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int low, int mid, int high, int* a){
    int i, j, k;
    int n1=mid-low + 1, n2= high-mid;
    int l[n1], r[n2];

    for (i=0; i< n1; i++)
        l[i]=a[low+i];
    for(j=0; j<n2; j++)
        r[j]=a[mid + j + 1];
        
    i=j=0;
    for(k=low; i<n1 && j< n2; k++){
        if (l[i]<=r[j])
            a[k]=l[i++];
        else
            a[k]=r[j++];
    }
    while(i < n1)
        a[k++]=l[i++];
    while(j<n2)
        a[k++]=r[j++];
}

void merge_sort(int low, int high, int *a){
    if (low<high){
        int mid=(high+low)/2;
        merge_sort(low, mid, a);
        merge_sort(mid+1, high, a);
        merge(low, mid, high, a);
    }
}

void main(){
    int i, n, *a; 
    double clk;
    clock_t end, start;
    srand(time(0));
    // scanf("%d", &n);
    for(n=10; n<=10000; n*=10){
        a=(int *)malloc(sizeof(int)*n);
        for (i=0; i<n; i++)
            a[i]=rand()%(n*10);
        //     printf("%d\t", a[i]);
        // }
        // printf("\n");
        start=clock();
        merge_sort(0, n-1, a);
        end=clock();
        // for (i=0; i<n; i++){
        //     printf("%d\t", a[i]);
        // }
        clk=(double)(end-start)/CLOCKS_PER_SEC;
        printf("\nruntime=%lf\n", clk);
        free(a);
    }
}
