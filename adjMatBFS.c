#include<stdio.h>
#include<stdlib.h>
#include "bfsQueue.h"

void accept(int **adjMat, int nodes) {
    int i,j;
    int isDirectedGraph = 0;
    printf("Undirected/Directed (0/1): ");
    scanf("%d",&isDirectedGraph);

    for(i = 1; i < nodes; i++){
        for(j = 1; j < nodes; j++) {
            if(i == j) continue;
            if(adjMat[i][j] == 1)continue;

            int edge;
            printf("Edge? %d -> %d (1/0): ", i, j);
            scanf("%d",&edge);
            
            if(isDirectedGraph)
            adjMat[i][j] = edge;
            else {
                adjMat[i][j] = edge;
                adjMat[j][i] = edge;
            }
        } 
    }
}

void bfs(int **adjMat, int nodes, int *vis, int node) {
    Queue *q = NULL;
    
    int j;
    q = push(q,node);
    vis[node] = 1;

    while(!isEmpty(q)){
        int node = front(q);
        q = pop(q);

        printf("%d ",node);

        for(j = 1; j < nodes; j++) {
            if(node != j){
                if(adjMat[node][j] == 1 && !vis[j]){
                    q = push(q,j);
                    vis[j] = 1;
                }
            }
        }
    }
}

int main() {
    int nodes;
    printf("Enter nodes: ");
    scanf("%d",&nodes);

    int **adjMat = (int **)malloc(sizeof(int *) * nodes);
    int *vis = (int *)malloc(sizeof(int) * nodes);
    int i,j;
    for(i = 0; i < nodes; i++) {
        adjMat[i] = (int *)malloc(sizeof(int) * nodes);
    }
    for(i = 0; i < nodes; i++) {
        vis[i] = 0;
    }

    accept(adjMat, nodes);
    for(i = 1; i < nodes; i++) {
        if(!vis[i])bfs(adjMat, nodes, vis,i);
    }

    return 0;
}