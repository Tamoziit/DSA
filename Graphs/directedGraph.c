#include <stdio.h>
#include <stdlib.h>

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

void addDirectedEdge(Graph *graph, int src, int dest)
{
    // only adding edge from src->dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void printGraph(Graph *graph)
{
    int v;
    Node *temp;
    for (v = 0; v < graph->numVertices; v++)
    {
        temp = graph->adjList[v];
        printf("\nAdjacency list of %d:\n", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
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

int main()
{
    int n;
    printf("Enter no. of vertices:\n");
    scanf("%d", &n);

    Graph *graph = createGraph(n);
    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 0, 5);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 1, 6);
    addDirectedEdge(graph, 1, 4);
    addDirectedEdge(graph, 6, 2);
    addDirectedEdge(graph, 3, 6);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 4);
    addDirectedEdge(graph, 4, 6);
    addDirectedEdge(graph, 5, 4);
    printGraph(graph);

    int **matrix = (int **)malloc(n * sizeof(int *));
    int i, j;
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            matrix[i][j] = 0;
    }

    evaluateAdjMatrix(graph, matrix);
    printf("\nThe Adjacency Matrix:\n");
    printAdjMatrix(matrix, n);

    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}