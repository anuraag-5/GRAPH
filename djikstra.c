#include "dyQueue.h"
#include <stdlib.h>

void display(int *shortestPath, int vertices)
{
    int j;
    for (j = 0; j < vertices; j++)
    {
        printf("%d ", shortestPath[j]);
    }
}

void displayMat(int **adjMat, int vertices)
{
    int i, j;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
}

void djikstra(int **adjMat, int source, int *shortestPath, int vertices)
{
    struct Queue *q = NULL;
    q = enqueue(q, source, 0);
    shortestPath[source] = 0;

    while (!isEmpty(q))
    {
        int *node = peek(q);
        int vertice = node[0];
        int dist = node[1];

        for (int i = 0; i < vertices; i++)
        {
            if (i != vertice)
            {
                if ((adjMat[vertice][i] + dist) < shortestPath[i] && adjMat[vertice][i] != 0)
                {
                    shortestPath[i] = adjMat[vertice][i] + dist;
                    q = enqueue(q, i, adjMat[vertice][i] + dist);
                }
            }
        }

        q = q->next;
    }
}

void acceptEdgeWeights(int **adjMat, int vertices)
{
    int i, j, type;
    printf("Select\n0.Undirected Graph\n1.Directed Graph\n");
    scanf("%d", &type);

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if (i != j)
            {
                if (adjMat[i][j] != 0)
                {
                    continue;
                }

                int choice;
                printf("Edge weight %d -> %d: (Weight/0): ", i, j);
                scanf("%d", &choice);
                if (choice != 0)
                {
                    if (type)
                    {
                        adjMat[i][j] = choice;
                    }
                    else
                    {
                        adjMat[i][j] = choice;
                        adjMat[j][i] = choice;
                    }
                }
            }
        }
    }
}

int main()
{
    int vertices;
    printf("Enter vertices: ");
    scanf("%d", &vertices);

    int **adjMat = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        adjMat[i] = (int *)malloc(vertices * sizeof(int));
    }
    int i, j;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    acceptEdgeWeights(adjMat, vertices);
    int *shortestPath = (int *)malloc(sizeof(int) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        shortestPath[i] = 20000;
    }

    djikstra(adjMat, 0, shortestPath, vertices);
    display(shortestPath, vertices);

    return 0;
}