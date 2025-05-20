//johnson trotter algorithim
#include <stdio.h>
#include <stdlib.h>
#define LEFT -1
#define RIGHT 1
int get_largest_mobile(int perm[],int dir[],int n){
    int mobile=0;
    for(int i=0;i<n;i++){
        int next=i+dir[i];
        if(next>=0 && next<n && perm[i]>perm[next]){
            if(perm[i]>mobile){
                mobile=perm[i];
            }
        }
    }
    return mobile;
}

void print_permutation(int perm[],int n){
    for(int i=0;i<n;i++){
        printf("%d,",perm[i]);
    }
    printf("\n");
}

int get_index(int perm[],int n,int value){
    for (int i = 0; i < n; i++) {
           if (perm[i] == value)
               return i;
       }
       return -1;
}
void johson_trotter(int perm[],int dir[],int n){
    for(int i=0;i<n;i++){
        perm[i]=i+1;
        dir[i]=LEFT;
    }
    //print the first permutation
    print_permutation(perm, n);
    int c=1;
    
    while(1){
        int mobile=get_largest_mobile(perm, dir, n);
        if(mobile==0){
            break;
        }
        //index of mobile element
        int mob_index=get_index(perm,n,mobile);
        int swap_index = mob_index + dir[mob_index];
        //swapping the mobile element with its next
        int temp=perm[mob_index];
        perm[mob_index]=perm[swap_index];
        perm[swap_index]=temp;
        
        //swapping the directions of the so swapped elements
        int temp2=dir[mob_index];
        dir[mob_index]=dir[swap_index];
        dir[swap_index]=temp2;
        
        //if any larger element than the mobile elemnt is existing then reverse its direction also
        for(int i=0;i<n;i++){
            if(perm[i]>mobile){
                dir[i]=dir[i]*-1;
            }
        }
        print_permutation(perm, n);
        c++;
        
    }
    printf("\nTOTAL PERMUTATIONS--->:%d\n",c);
    
}

int main(void){
    int n=4;
    int perm[n];
    int dir[n];
    johson_trotter(perm, dir, n);
}
