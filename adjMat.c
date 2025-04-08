#include<stdio.h>
#include<stdlib.h>

void display(int **adjMat, int vertices) {
    int i,j;
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
}

void someMath(int **adjMat, int vertices) {
    int i;
    for(i = 0; i < vertices; i++) {
        int indegree = 0, outdegree = 0, j;
        
        for(j = 0; j < vertices; j++) {
            if(i != j){
                if(adjMat[j][i] == 1) {
                    indegree++;
                }
            }
        }

        for(j = 0; j < vertices; j++) {
            if(i != j){
                if(adjMat[i][j] == 1) {
                    outdegree++;
                }
            }
        }

        printf("\nIndegree for vertice: %d : %d.\nOutdegree for vertice: %d : %d.\nTotalDegree for vertice: %d : %d.\n",i,indegree,i,outdegree,i,indegree + outdegree);
    }
}

void acceptEdges(int **adjMat, int vertices) {
    int i,j,type;
    printf("Select\n0.Undirected Graph\n1.Directed Graph\n");
    scanf("%d",&type);

    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            if(i != j){
                if(adjMat[i][j] == 1) {
                    continue;
                }

                int choice;
                printf("Edge between %d -> %d: (1/0): ",i,j);
                scanf("%d",&choice);
                if(choice){
                    if(type){
                        adjMat[i][j] = 1;
                    } else {
                        adjMat[i][j] = 1;
                        adjMat[j][i] = 1;
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

    int **adjMat = (int**)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        adjMat[i] = (int *)malloc(vertices * sizeof(int));
    }
    int i,j;
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            adjMat[i][j] = 0;
        }
    }

    acceptEdges(adjMat, vertices);
    someMath(adjMat,vertices);
    display(adjMat,vertices);

    return 0;
}