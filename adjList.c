#include<stdio.h>
#include<stdlib.h>

typedef struct List {
    int neighbors[100];
} List;

void display(List *adjList, int vertices) {
    int i,j;
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ",adjList[i].neighbors[j]);
        }
        printf("\n");
    }
}

void someMath(List *adjList, int vertices) {
    int i;
    for(i = 0; i < vertices; i++) {
        int indegree = 0, outdegree = 0, j;
        
        for(j = 0; j < vertices; j++) {
            if(i != j){
                if(adjList[j].neighbors[i] == 1) {
                    indegree++;
                }
            }
        }

        for(j = 0; j < vertices; j++) {
            if(i != j){
                if(adjList[i].neighbors[j] == 1) {
                    outdegree++;
                }
            }
        }

        printf("\nIndegree for vertice: %d : %d.\nOutdegree for vertice: %d : %d.\nTotalDegree for vertice: %d : %d.\n",i,indegree,i,outdegree,i,indegree + outdegree);
    }
}

void acceptEdges(List *adjList, int vertices) {
    int i,j,type;
    printf("Select\n0.Undirected Graph\n1.Directed Graph\n");
    scanf("%d",&type);

    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            if(i != j){
                if(adjList[i].neighbors[j] == 1) {
                    continue;
                }

                int choice;
                printf("Edge between %d -> %d: (1/0): ",i,j);
                scanf("%d",&choice);
                if(choice){
                    if(type){
                        adjList[i].neighbors[j] = 1;
                    } else {
                        adjList[i].neighbors[j] = 1;
                        adjList[j].neighbors[i] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int vertices;
    printf("Enter vertices: ");
    scanf("%d",&vertices);

    List *adjList = (List*)malloc(vertices * sizeof(List));

    int i,j;
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            adjList[i].neighbors[j] = 0;
        }
    }

    acceptEdges(adjList, vertices);
    someMath(adjList, vertices);
    display(adjList, vertices);

    return 0;
}