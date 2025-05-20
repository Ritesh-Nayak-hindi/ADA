//merge sort
#include <stdio.h>
#include <stdlib.h>
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

int main(){
    int A[]={1,34,56,22,3333,456,12234,0};
    int n=sizeof(A)/sizeof(A[0]);
    int *sorted=merge_sort(A, n);
    
    for(int i=0;i<n;i++){
        printf("%d ",sorted[i]);
    }
    
}
