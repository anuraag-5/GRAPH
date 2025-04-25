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
            printf("Edge? %d -> %d (1/0): ",i,j);
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

void display(int **adjMat, int nodes) {
    int i,j;

    for(i = 1; i < nodes; i++){
        for(j = 1; j < nodes; j++) {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
}

void indegree(int **adjMat, int nodes) {
    int i,j;
    for(i = 1; i < nodes; i++) {
        int indegree = 0;
        for(j = 1; j < nodes; j++) {
            if(i != j){
                if(adjMat[j][i] == 1) indegree++;
            }
        }
        printf("Indegree for %d: %d\n",i,indegree);
    }
}

void outdegree(int **adjMat, int nodes) {
    int i,j;
    for(i = 1; i < nodes; i++) {
        int outdegree = 0;
        for(j = 1; j < nodes; j++) {
            if(i != j){
                if(adjMat[i][j] == 1) outdegree++;
            }
        }
        printf("Outdegree for %d: %d\n",i,outdegree);
    }
}

void totaldegree(int **adjMat, int nodes) {
    int i,j;
    for(i = 1; i < nodes; i++) {
        int indegree = 0;
        for(j = 1; j < nodes; j++) {
            if(i != j){
                if(adjMat[j][i] == 1) indegree++;
            }
        }

        int outdegree = 0;
        for(j = 1; j <= nodes; j++) {
            if(i != j){
                if(adjMat[i][j] == 1) outdegree++;
            }
        }
        printf("TotalDegree for %d: %d\n",i,indegree+outdegree);
    }
}

int main() {
    int nodes;
    printf("Enter number of nodes: ");
    scanf("%d",&nodes);

    int **adjMat = (int**)malloc(sizeof(int*) * nodes);
    int i,j;

    for(i = 0; i < nodes; i++) {
        adjMat[i] = (int *)malloc(sizeof(int) * nodes);
    }

    for(i = 0; i < nodes; i++){
        for(j = 0; j < nodes; j++) {
            adjMat[i][j] = 0;
        } 
    }

    accept(adjMat,nodes);
    int choice;

    while(choice != 5) {
        printf("Choose\n1.Display\n2.Indegree\n3.OutDegree\n4.TotalDegree\n5.Exit\n");
        scanf("%d",&choice);

        switch (choice){
            case 1:
            display(adjMat, nodes);
            break;
           
            case 2:
            indegree(adjMat, nodes);
            break;

            case 3:
            outdegree(adjMat, nodes);
            break;

            case 4:
            totaldegree(adjMat, nodes);
            break;

            case 5:
            printf("Exiting...\n");
            break;
            
            default:
            printf("Incorrect choice\n");
        }
    }

    return 0;
}