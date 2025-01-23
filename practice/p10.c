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
    struct node **adjList;
} Graph;

Node *createNode(int v)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->vertex = v;
    new->next = NULL;

    return new;
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

void printGraph(Graph *graph)
{
    int v;
    for (v = 0; v <= graph->numVertices; v++)
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

int main()
{
    Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 1);
    addEdge(graph, 5, 6);
    printGraph(graph);
    return 0;
}