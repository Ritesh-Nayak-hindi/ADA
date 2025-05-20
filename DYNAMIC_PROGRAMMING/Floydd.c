//floyyds algorithim
#include <stdio.h>
#include <stdlib.h>
#define V 4
#define INF 999999
typedef struct {
    int G[V][V];
}Graph;

Graph * create_graph(void){
    Graph * g =(Graph *)malloc(sizeof(Graph));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                g->G[i][j]=0;
            }
            else{
                g->G[i][j]=INF;
            }
        }
    }
    
    return g;
}

// giving the values of a weighted graoph here
void add_edge(Graph *g, int weight,int src,int dest){
    if(g->G[src-1][dest-1]==INF){
        g->G[src-1][dest-1]=weight;
    }
}

void initialize_result(Graph *g,int result[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            result[i][j]=g->G[i][j];
        }
    }
}

void Floydd(Graph *g,int result[V][V]){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(result[i][k]+result[k][j]<result[i][j]){
                    result[i][j]=result[i][k]+result[k][j];
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(result[i][j]==INF){
                printf("THE SHORTEST DISTANCE FROM %d--->%d IS:infinity\n",i+1,j+1);
            }
            else{
                printf("THE SHORTEST DISTANCE FROM %d--->%d IS:%d\n",i+1,j+1,result[i][j]);
            }
        }
    }
}

int main(void){
    Graph *g=create_graph();
    add_edge(g, 3, 1, 2);
    add_edge(g, 8, 2,1);
    add_edge(g, 7, 1, 4);
    add_edge(g, 2, 4, 1);
    add_edge(g, 2, 2, 3);
    add_edge(g, 5, 3, 1);
    add_edge(g, 1, 3, 4);
    int result[V][V];
    initialize_result(g, result);
    Floydd(g, result);
    
}
