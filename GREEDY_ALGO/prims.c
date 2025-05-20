//prims algorithim to find the MST
#include <stdio.h>
#include <stdlib.h>
#define V 5
#define INF 9999999

int get_min_dist_index(int key[],int setMST[]){
    int min_key=INF;
    int index=-1;
    for(int i=0;i<V;i++){
        if(!setMST[i] && key[i]<min_key){
            min_key=key[i];
            index=i;
        }
    }
    return index;
}

//algorithim to fin the MST
void prims(int key[],int parent[],int setMST[],int G[V][V]){
    //initialize the key and the MST values for all of them
    for(int i=0;i<V;i++){
        key[i]=INF;
        setMST[i]=0;
    }
    
    parent[0]=-1;
    key[0]=0;//here the distance of the forst node from itself is 0
    for(int i=1;i<V;i++){
        int u=get_min_dist_index(key, setMST);
        setMST[u]=1;
        // then update the key with new distances from this new parent
        for(int j=0;j<V;j++){
            if(G[u][j] && !setMST[j] && G[u][j]<key[j]){
                parent[j]=u;
                key[j]=G[u][j];
            }
        }
    }
    
    //print the mst
    for(int i=1;i<V;i++){
        printf("%d---->%d-dist:%d\n",parent[i],i,G[parent[i]][i]);
    }
}

int main(void){
    int G[V][V] = {
           {0, 2, 0, 6, 0},
           {2, 0, 3, 8, 5},
           {0, 3, 0, 0, 7},
           {6, 8, 0, 0, 9},
           {0, 5, 7, 9, 0}
       };
    
    int key[V];
    int setMST[V];
    int parent[V];
    prims(key, parent, setMST, G);
}
