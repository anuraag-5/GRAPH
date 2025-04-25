#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *data;
} Nodes;

void init(Nodes *n, int nodes){
    n -> data = (int *)malloc(sizeof(int) * nodes);
}

void accept(Nodes *adjList, int nodes) {
    int i,j;
    int isDirectedGraph = 0;
    printf("Undirected/Directed (0/1): ");
    scanf("%d",&isDirectedGraph);

    for(i = 1; i < nodes; i++){
        for(j = 1; j < nodes; j++) {
            if(i == j) continue;
            if(adjList[i].data[j] == 1)continue;

            int edge;
            printf("Edge? %d -> %d (1/0): ",i,j);
            scanf("%d",&edge);
            
            if(isDirectedGraph)
            adjList[i].data[j] = edge;
            else {
                adjList[i].data[j] = edge;
                adjList[j].data[i] = edge;
            }
        } 
    }
}

void display(Nodes *adjList, int nodes) {
    int i,j;

    for(i = 1; i < nodes; i++){
        for(j = 1; j < nodes; j++) {
            printf("%d ",adjList[i].data[j]);
        }
        printf("\n");
    }
}

void indegree(Nodes *adjList, int nodes) {
    int i,j;
    for(i = 1; i < nodes; i++) {
        int indegree = 0;
        for(j = 1; j < nodes; j++) {
            if(i != j){
                if(adjList[j].data[i] == 1) indegree++;
            }
        }
        printf("Indegree for %d: %d\n",i,indegree);
    }
}

void outdegree(Nodes *adjList, int nodes) {
    int i,j;
    for(i = 1; i < nodes; i++) {
        int outdegree = 0;
        for(j = 1; j < nodes; j++) {
            if(i != j){
                if(adjList[i].data[j] == 1) outdegree++;
            }
        }
        printf("Outdegree for %d: %d\n",i,outdegree);
    }
}

void totaldegree(Nodes *adjList, int nodes) {
    int i,j;
    for(i = 1; i < nodes; i++) {
        int indegree = 0;
        for(j = 1; j < nodes; j++) {
            if(i != j){
                if(adjList[j].data[i] == 1) indegree++;
            }
        }

        int outdegree = 0;
        for(j = 1; j <= nodes; j++) {
            if(i != j){
                if(adjList[i].data[j] == 1) outdegree++;
            }
        }
        printf("TotalDegree for %d: %d\n",i,indegree+outdegree);
    }
}

int main() {
    int nodes;
    printf("Enter number of nodes: ");
    scanf("%d",&nodes);

    Nodes *adjList = (Nodes *)malloc(sizeof(Nodes) * nodes);
    int i,j;
    for(i = 0; i < nodes; i++){
        init(&adjList[i], nodes);
    }

    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            adjList[i].data[j] = 0;
        }
    }

    accept(adjList, nodes);
    int choice = 0;

    while(choice != 5) {
        printf("Choose\n1.Display\n2.Indegree\n3.OutDegree\n4.TotalDegree\n5.Exit\n");
        scanf("%d",&choice);

        switch (choice){
            case 1:
            display(adjList, nodes);
            break;
           
            case 2:
            indegree(adjList, nodes);
            break;

            case 3:
            outdegree(adjList, nodes);
            break;

            case 4:
            totaldegree(adjList, nodes);
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