#include<stdio.h>
#include<stdlib.h>
#include "queue.c"

typedef struct node{
    int dest;
    int weight;
    struct node *next;
}node;

typedef struct graph{
    int numvertices;
    node **adjlist;
}graph;

void initGraph(graph *g, int vertices){
    g->numvertices = vertices;
    g->adjlist = (node **)malloc(vertices * sizeof(node*));

    for (int i = 0; i < vertices; i++) {
        g->adjlist[i] = NULL;
    }
}
    


node *createnode(int dest, int weight){
    node *nn = (node*)malloc(sizeof(node));
    nn->dest =dest;
    nn->weight = weight;
    nn->next = NULL;
    return nn ;
}

void addEdge(graph *g, int src, int dest, int weight){
    node *nn = createnode(dest, weight);
    nn->next= g->adjlist[src];
    g->adjlist[src] = nn;

    nn = createnode(src, weight);
    nn->next = g->adjlist[dest];
    g->adjlist[dest] = nn ;
}

void display(graph *g){
    for(int i = 0; i< g->numvertices; i++){
        node *temp = g->adjlist[i];
        printf("Vertex %d |", i);

        while(temp){
            printf("-> %d  (weight : %d)", temp ->dest, temp ->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void removeEdge(graph* g, int src, int dest) {
    // Remove edge from src to dest
    node* temp = g->adjlist[src];
    node* prev = NULL;

    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            // The edge to be removed is the first node
            g->adjlist[src] = temp->next;
        } else {
            // The edge is somewhere in the middle or end
            prev->next = temp->next;
        }
        free(temp); // Free the memory allocated for the node
    }

    // Remove edge from dest to src (if undirected)
    temp = g->adjlist[dest];
    prev = NULL;

    while (temp != NULL && temp->dest != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            // The edge to be removed is the first node
            g->adjlist[dest] = temp->next;
        } else {
            // The edge is somewhere in the middle or end
            prev->next = temp->next;
        }
        free(temp); // Free the memory allocated for the node
    }
}


void BFS(graph *g, int startvertex){
    queue q;
    qinit(&q, g->numvertices);
    int *visited =(int *)calloc(g->numvertices, sizeof(int));
    eneque(&q, startvertex);
    visited[startvertex] = 1;

    printf("BFS: ");
    while(!isEmpty(&q)){
        int currentVertex = deque(&q);
        printf("%d ", currentVertex);

        node *temp = g->adjlist[currentVertex];
        while(temp){
            int adjVertex = temp->dest;
            if(!visited[adjVertex]){
                visited[adjVertex] = 1;
                eneque(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main (){
    int vertices = 4;
    graph g;
    initGraph(&g, vertices);
    addEdge(&g, 0, 1, 1);
    addEdge(&g, 0, 2, 1);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 2, 3, 1);

    printf("Graph : \n");
    display(&g);
    BFS(&g, 0);

    removeEdge(&g, 0, 1);
    removeEdge(&g, 2, 1);
    removeEdge(&g, 3, 2);
    display(&g);

    BFS(&g, 0);




    return 0;
}