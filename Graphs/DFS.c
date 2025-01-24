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
    for (int i = 0; i < v; i++)
        graph->adjList[i] = NULL;
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
    for (int v = 0; v < graph->numVertices; v++)
    {
        Node *temp = graph->adjList[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void dfs(Graph *graph, int u, char *color, int *d, int *pi, int *time)
{
    printf("Exploring vertex: %d\n", u);
    color[u] = 'g';   // Marking vertex as gray (discovered)
    d[u] = ++(*time); // Recording discovery time

    Node *temp = graph->adjList[u]; // Starting with the adjacency list of vertex `u`
    while (temp)                    // Traversing all adjacent vertices
    {
        if (color[temp->vertex] == 'w') // If the vertex is white (undiscovered)
        {
            pi[temp->vertex] = u;                         // Setting predecessor
            dfs(graph, temp->vertex, color, d, pi, time); // Recursively visit
        }
        temp = temp->next; // Moving to the next adjacent vertex
    }

    color[u] = 'b';   // Marking vertex as black (finished)
    d[u] = ++(*time); // Recording finish time
}

void printPredecessorSubgraph(int *pi, int n)
{
    printf("\nPredecessor Subgraph (DFS Tree):\n");
    for (int i = 0; i < n; i++)
    {
        if (pi[i] != -1)
            printf("%d -> %d\n", pi[i], i); // Printing parent -> child
        else
            printf("%d is a root of the DFS tree\n", i); // Root of a DFS tree
    }
}

int main()
{
    int n;
    printf("Enter no. of vertices:\n");
    scanf("%d", &n);

    Graph *graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 6);
    addEdge(graph, 1, 4);
    addEdge(graph, 6, 2);
    addEdge(graph, 3, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 4);
    printGraph(graph);

    char *color = (char *)malloc(n * sizeof(char));
    int *d = (int *)malloc(n * sizeof(int));
    int *pi = (int *)malloc(n * sizeof(int));

    // Initial state
    int time = 0, u;
    for (u = 0; u < graph->numVertices; u++)
    {
        color[u] = 'w';
        d[u] = 9999;
        pi[u] = -1;
    }
    printf("\nStarting DFS\n");

    // DFS for each vertex
    for (u = 0; u < graph->numVertices; u++)
    {
        if (color[u] == 'w')
            dfs(graph, u, color, d, pi, &time);
    }

    printf("\nVertex  Color  Distance  Predecessor\n");
    for (u = 0; u < graph->numVertices; u++)
        printf("\n  %d       %c      %d         %d\n", u, color[u], d[u], pi[u]);

    printPredecessorSubgraph(pi, n);

    free(color);
    free(d);
    free(pi);
    return 0;
}
