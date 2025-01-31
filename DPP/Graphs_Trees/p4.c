/*
    Square of Matrix:
    A^2[u][w] = ∑A[u][v].A[v][w] (summation from v=1 to n)
*/

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int count = 0;
int queue[100];

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

typedef struct graph
{
    int numVertices;
    Node **adjList;
} Graph;

void enqueue(int n)
{
    queue[++rear] = n;
    if (rear == 0)
        front = 0;
    count++;
}

void dequeue()
{
    int temp = queue[front++];
    count--;
}

int isEmptyQueue()
{
    if (count > 0)
        return 0;
    return 1;
}

int peakFront()
{
    return queue[front];
}

Node *createNode(int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = n;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = v;
    graph->adjList = (Node **)malloc(v * sizeof(Node *));

    int i;
    for (i = 0; i < v; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjList[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
}

void evaluateAdjMatrix(Graph *graph, int **matrix)
{
    int v;
    Node *temp;
    for (v = 0; v < graph->numVertices; v++)
    {
        temp = graph->adjList[v];
        while (temp)
        {
            matrix[v][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    free(temp);
}

void printAdjMatrix(int **matrix, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void computeG2(int **G, int **G2, int n)
{
    int u, v, w;
    for (u = 0; u < n; u++)
    {
        for (w = 0; w < n; w++)
            G2[u][w] = 0;
    }

    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            if (G[u][v])
            {
                for (w = 0; w < n; w++)
                {
                    if (G[v][w])
                    {
                        G2[u][w] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int numVertices = 4, i;
    Graph *graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);

    printf("Graph adjacency list:\n");
    printGraph(graph);

    int **adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    int **adjMatrixSquared = (int **)malloc(numVertices * sizeof(int *));
    for (i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        adjMatrixSquared[i] = (int *)malloc(numVertices * sizeof(int));
    }

    evaluateAdjMatrix(graph, adjMatrix);

    printf("\nAdjacency Matrix:\n");
    printAdjMatrix(adjMatrix, numVertices);

    // Computing the squared adjacency matrix
    computeG2(adjMatrix, adjMatrixSquared, numVertices);

    printf("\nSquared Adjacency Matrix:\n");
    printAdjMatrix(adjMatrixSquared, numVertices);

    for (i = 0; i < numVertices; i++)
    {
        free(adjMatrix[i]);
        free(adjMatrixSquared[i]);
    }
    free(adjMatrix);
    free(adjMatrixSquared);

    for (i = 0; i < numVertices; i++)
        free(graph->adjList[i]);
    free(graph);

    return 0;
}