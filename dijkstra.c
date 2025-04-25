#include "djQueue.h"

void accept(int **adjMat, int nodes) {
    int i,j;
    int isDirectedGraph = 0;
    printf("Undirected/Directed (0/1): ");
    scanf("%d",&isDirectedGraph);

    for(i = 1; i < nodes; i++){
        for(j = 1; j < nodes; j++) {
            if(i == j) continue;
            if(adjMat[i][j] != 0)continue;

            int edge;
            printf("Edge? %d -> %d (weight/0): ",i,j);
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

void dijkstra(int **adjMat, int vertices, int *dis){
    Queue *q = NULL;
    q = push(q,1,0);
    dis[1] = 0;

    int i;
    while(!isEmpty(q)){
        int *nodes = front(q);
        int node = nodes[0];
        int dist = nodes[1];
        q = pop(q);

        for(i = 1; i < vertices; i++) {
            if(i != node){
                if(adjMat[node][i] != 0 && (dist + adjMat[node][i]) < dis[i]){
                    dis[i] = dist + adjMat[node][i];
                    q = push(q,i,dist + adjMat[node][i]);
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
    int *dis = (int *)malloc(sizeof(int) * nodes);
    int i,j;
    for(i = 0; i < nodes; i++) {
        adjMat[i] = (int *)malloc(sizeof(int) * nodes);
    }

    for(i = 0; i < nodes; i++){
        for(j = 0; j < nodes; j++) {
            adjMat[i][j] = 0;
        } 
    }

    for(i = 0; i < nodes; i++) {
        dis[i] = 200000;
    }
    accept(adjMat, nodes);
    
    dijkstra(adjMat, nodes, dis);
    
    for(i = 1; i < nodes; i++) {
        printf("%d: %d\n",i,dis[i]);
    }

    return 0;
}