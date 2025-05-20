#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int *left,int left_l,int *right,int right_l,int *result){
    int i=0;
    int j=0;
    int k=0;
    while(i<left_l && j<right_l){
        if(left[i]<=right[j]){
            result[k++]=left[i++];
        }
        else{
            result[k++]=right[j++];
        }
    }
    if(i==left_l){
        while(j<right_l){
            result[k++]=right[j++];
        }
    }
    else{
        while(i<left_l){
            result[k++]=left[i++];
        }
    }
}

int *  merge_sort(int *A,int n){
    if(n<=1){
        int *temp=(int *)malloc(sizeof(int)*n);
        if(n==1){
            temp[0]=A[0];
        }
        return temp;
    }
    int mid =n/2;
    int *left=merge_sort(A, mid);
    int *right=merge_sort(A+mid, n-mid);
    int *sorted=(int *)malloc(sizeof(int)*n);
    merge(left, mid, right, n-mid, sorted);
    return sorted;
}

int main(void){
    int n=10000;
    int A[n];
    for(int i=0;i<n;i++){
        A[i]=rand()%10000;
    }
    
    
    clock_t start=clock();
    int *sorted=merge_sort(A, n);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    
    for(int i=0;i<n;i++){
        printf("%d ",sorted[i]);
    }
    
    printf("\nTIME TAKEN: %6f",time_taken);
    
}
