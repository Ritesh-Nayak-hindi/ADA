// fractional knapsack algorithim
#include <stdio.h>
#include <stdlib.h>
#define W 15



// items structiure
typedef struct {
    int profit;
    int weigth;
    double value;
    int index;
}Item;


void merge(Item B[],int left_l,Item C[],int right_l,Item result[]){
    int i=0;
    int j=0;
    int k=0;
    while(i<left_l && j<right_l){
        if(B[i].value<C[j].value){
            result[k++]=C[j++];
        }
        else{
            result[k++]=B[i++];
        }
    }
    
    while(i<left_l){
        result[k++]=B[i++];
    }
    
    while(j<right_l){
        result[k++]=C[j++];
    }
    
    
}

Item * merge_sort(Item A[],int n){
    if(n<=1){
        Item *temp=(Item *)malloc(sizeof(Item)*n);
        if(n==1){
            temp[0]=A[0];
        }
        return temp;
    }
    int mid=n/2;
    Item *left=merge_sort(A, mid);
    Item *rigth=merge_sort(A+mid, n-mid);
    Item *sorted=(Item *)malloc(sizeof(Item)*n);
    merge(left, mid, rigth, n-mid, sorted);
    free(left);
    free(rigth);
    return sorted;
    
}



void fractional_knapsack(Item I[],int n){
    int w=0;
    for(int i=0;i<n;i++){
        I[i].value=(double)(I[i].profit)/(I[i].weigth);
    }
    double *x=(double *)malloc(sizeof(double)*n);
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    Item *Item_sorted =merge_sort(I, n);
    
    int i=0;
    while(w<W && i<n){
        if(Item_sorted[i].weigth<=W-w){
            x[Item_sorted[i].index]=1.0;// entrirte object can be taken
            w=w+Item_sorted[i].weigth;
        }
        else{
            x[Item_sorted[i].index]= (double)(W-w)/Item_sorted[i].weigth;
            w=W;
        }
        i++;
    }
    
    // how many of items were taken
    for(int i=0;i<n;i++){
        printf("Item %d --- Quantity:%f\n",i+1,(float)(x[i]*I[i].weigth));
    }
    double total=0;
    for(int i=0;i<n;i++ ){
        total+=I[i].profit*x[i];
    }
    printf("TOTAL MONEY MADE IS:%6f",total);
    free(Item_sorted);
    free(x);
    
}

int main(void){
    int n=7;
    Item I[n];
    for(int i=0;i<n;i++){
        printf("ENTER THE PROFIT OF ITEM%d:",i+1);
        scanf("%d",&I[i].profit);
        printf("ENTER THE WEIGHT OF ITEM%d:",i+1);
        scanf("%d",&I[i].weigth);
        I[i].index=i;
    }
    fractional_knapsack(I, n);
}
