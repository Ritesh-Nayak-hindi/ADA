//heap sort
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int H[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    //comparing whuch one of the R,l,r are the maximum
    if(l<n && H[l]>H[largest]){
        largest=l;
    }
    if(r<n && H[r]>H[largest]){
        largest=r;
    }
    
    //ensuring the parental dominance of the given heap
    if(largest!=i){
        swap(&H[i], &H[largest]);
        heapify(H, n, largest);
    }
}
void create_heap(int H[],int n){
//    for(int i=(n/2)-1 ;i>=0;i--){
//        int k=i;
//        int v=H[k];
//        bool heap=false;
//        while(!heap && 2 * k + 1<n){
//            int j=(2*k)+1;
//            if(j+1<n && H[j]<H[j+1]){
//                j++;
//            }
//            if(v>=H[j]){
//                heap=true;
//            }
//            else{
//                H[k]=H[j];//pull the child up
//                k=j;
//            }
//        }
//        H[k]=v;
//    }
    
    //alternative version
    for(int i=(n/2)-1 ;i>=0;i--){
        heapify(H, n, i);
    }
}




int removal_of_largest(int H[],int n){
    
    swap(&H[0], &H[n-1]);
    n=n-1;
    heapify(H, n, 0);
    return n;
}

void heap_sort(int H[],int n,int sorted[]){
    int size =n;
    create_heap(H, size);
    for(int i=n-1;i>=0;i--){
        sorted[i]=H[0];
        size=removal_of_largest(H, size);
    }
}

int main(void){
    
    int arr[]={23,12,22,56,788,1000,998738,12,33,2,1,4,5};
    int n=sizeof(arr)/sizeof(int);
    int sorted[n];
    heap_sort(arr, n, sorted);
    for(int i=0;i<n;i++){
        printf("%d ",sorted[i]);
    }
    
    
}

