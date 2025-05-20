//quick sort
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//partion algorithim
int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(i<j){
        do{
            i++;
        }while(i<=h && arr[i]<=pivot);
        do{
            j--;
        }while(j>=l && arr[j]>pivot);
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quick_sort(int arr[],int l,int h){
    if(l<h){
        int j=partition(arr, l, h);
        quick_sort(arr, l, j-1);
        quick_sort(arr, j+1, h);
       
    }
   
}

int main(void){
    int arr[]={23,45,12,333,56,90,0};
    int n=sizeof(arr)/sizeof(int);
   
    quick_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
}
