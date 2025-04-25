#include<stdio.h>
#include<stdlib.h>

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

void dfs(int **adjMat, int nodes, int *vis, int node) {
    vis[node] = 1;
    printf("%d ",node);
    int i;

    for(i = 1; i < nodes; i++) {
        if(i != node) {
            if(adjMat[node][i] == 1 && !vis[i])dfs(adjMat,nodes,vis,i);
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
        if(!vis[i])dfs(adjMat, nodes, vis,i);
    }

    return 0;
}