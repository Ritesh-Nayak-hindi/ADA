typedef struct{
    int G[MAX_NODES][MAX_NODES];
    int number_of_vertices;
    int indegree[MAX_NODES];
} Graph;

Graph * create_graph(int n){
    Graph *g=(Graph *)malloc(sizeof(Graph));
    g->number_of_vertices=n;
    for(int i=0;i<n;i++){
        g->indegree[i]=0;
        for(int j=0;j<n;j++){
            g->G[i][j]=0;
        }
    }
    return g;
}
void add_edge(Graph *g,int src,int dest){
    if(g->G[src][dest]==0){
        g->G[src][dest]=1;
        g->indegree[dest]++;
    }
}

void topological_sort(Graph *g){
    int queue[MAX_NODES];
    int front=0;
    int rear=0;
    int count=0;
    for(int i=0;i<g->number_of_vertices;i++){
        if(g->indegree[i]==0){
            queue[rear++]=i;
        }
    }
    printf("TOPOLOGICAL ORDER\n");
    while(front<rear){//untill the queue is empty
        int u=queue[front++];
        printf("%d-->",u);
        count++;
        for(int v=0;v<g->number_of_vertices;v++){
            if(g->G[u][v]){
                g->G[u][v]=0;
                g->indegree[v]--;
                if(g->indegree[v]==0){
                    queue[rear++]=v;
                }
            }
           
        }
    }
    
    if(count!=g->number_of_vertices){
        printf("CYCLE IS DETECTED");
    }
    else{
        printf("end\n");
    }
}

void free_graph(Graph *g){
    free(g);
}
