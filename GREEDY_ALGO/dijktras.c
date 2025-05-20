#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // Number of vertices

// Min Heap Node
struct MinHeapNode {
    int v, dist;
};

// Min Heap structure
struct MinHeap {
    int size, capacity;
    int *pos;
    struct MinHeapNode **array;
};

// Create new node
struct MinHeapNode* newNode(int v, int dist) {
    struct MinHeapNode* node = malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

// Create Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = malloc(sizeof(struct MinHeap));
    heap->pos = malloc(V * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

// Swap two nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index i
void minHeapify(struct MinHeap* heap, int i) {
    int smallest = i, left = 2*i + 1, right = 2*i + 2;
    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;
    if (smallest != i) {
        struct MinHeapNode* smallestNode = heap->array[smallest];
        struct MinHeapNode* iNode = heap->array[i];

        heap->pos[smallestNode->v] = i;
        heap->pos[iNode->v] = smallest;

        swapMinHeapNode(&heap->array[smallest], &heap->array[i]);
        minHeapify(heap, smallest);
    }
}

// Check if heap is empty
int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

// Extract min node
struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap)) return NULL;
    struct MinHeapNode* root = heap->array[0];
    struct MinHeapNode* last = heap->array[--heap->size];
    heap->array[0] = last;

    heap->pos[root->v] = heap->size;
    heap->pos[last->v] = 0;

    minHeapify(heap, 0);
    return root;
}

// Decrease key of vertex v
void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i-1)/2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if vertex v is in heap
int isInMinHeap(struct MinHeap *heap, int v) {
    return heap->pos[v] < heap->size;
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        heap->array[v] = newNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src]->dist = dist[src] = 0;
    decreaseKey(heap, src, 0);
    heap->size = V;

    while (!isEmpty(heap)) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(heap, v, dist[v]);
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d\t%d\n", i, dist[i]);
}

// Sample usage
int main() {
    int graph[V][V] = {
        {0, 9, 6, 0, 0},
        {9, 0, 3, 5, 0},
        {6, 3, 0, 4, 2},
        {0, 5, 4, 0, 7},
        {0, 0, 2, 7, 0}
    };

    dijkstra(graph, 0);  // Source = 0
    return 0;
}

