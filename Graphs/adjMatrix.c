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

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int n)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->adjList = (Node **)malloc((n + 1) * sizeof(Node *));

    int i;
    for (i = 0; i <= n; i++)
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

void printAdjLists(Graph *graph)
{
    int v;
    Node *temp;
    for (v = 0; v <= graph->numVertices; v++)
    {
        temp = graph->adjList[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }

    free(temp);
}

void evaluateAdjMatrix(Graph *graph, int **matrix)
{
    int v;
    Node *temp;
    for (v = 0; v <= graph->numVertices; v++)
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
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, src, dest, ch;
    printf("Enter max vertex index\n");
    scanf("%d", &n);

    Graph *graph = createGraph(n);
    printf("Enter src & dest pairs, -1 to stop\n");
    while (1)
    {
        printf("Src, Dest.\n");
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
        printf("Continue?\n");
        scanf("%d", &ch);
        if (ch == -1)
            break;
    }
    printAdjLists(graph);

    int **matrix = (int **)malloc((n + 1) * sizeof(int *));
    int i, j;
    for (i = 0; i <= n; i++)
    {
        matrix[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
            matrix[i][j] = 0;
    }

    evaluateAdjMatrix(graph, matrix);
    printf("\nThe Adjacency Matrix:\n");
    printAdjMatrix(matrix, n);

    for (i = 0; i <= n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}