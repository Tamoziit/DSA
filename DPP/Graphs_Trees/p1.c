/*
    Closeness Centrality: How close is source from all other vertices

    Closeness Centrality of source 's' from vertices 'v' is given by,
    C(s) = (|V|-1)/(∑d(s,v)) [summation for all v, such that, v≠s]

    C(s) high --> s to closer to other vertices v.
    C(s) low --> s if farther from other vertices v.
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

void bfs(Graph *graph, int s, char *color, int *d, int *pi)
{
    int v;
    Node *temp;
    for (v = 0; v < graph->numVertices; v++)
    {
        if (v != s)
        {
            color[v] = 'w';
            d[v] = 9999;
            pi[v] = -1;
        }
    }
    color[s] = 'g';
    d[s] = 0;
    pi[s] = -1;
    enqueue(s);

    while (!isEmptyQueue())
    {
        v = peakFront();
        temp = graph->adjList[v];
        while (temp)
        {
            if (color[temp->vertex] == 'w')
            {
                color[temp->vertex] = 'g';
                d[temp->vertex] = d[v] + 1;
                pi[temp->vertex] = v;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
        dequeue();
        color[v] = 'b';
    }
}

void printPath(Graph *graph, int *pi, int s, int v)
{
    if (v == s)
        printf(" %d", s);
    else if (pi[v] == -1)
        printf("No path from %d to %d exists", s, v);
    else
    {
        printPath(graph, pi, s, pi[v]);
        printf(" -> %d", v);
    }
}

float closenessCentrality(Graph *graph, int s, int *d)
{
    int v;
    float res, sum = 0.0;
    for (v = 0; v < graph->numVertices; v++)
    {
        if (v != s)
            sum += d[v];
    }

    res = (graph->numVertices - 1) / (float)sum;
    return res;
}

int main()
{
    int n, s;
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

    printf("\nEnter source for BFS:\n");
    scanf("%d", &s);
    int v;
    bfs(graph, s, color, d, pi);

    printf("\nVertex  Color  Distance  Predecessor\n");
    for (v = 0; v < graph->numVertices; v++)
        printf("\n  %d       %c      %d         %d\n", v, color[v], d[v], pi[v]);
    printf("\nPredecessor Subgraph\n");
    for (v = 0; v < graph->numVertices; v++)
    {
        if (v != s)
        {
            printPath(graph, pi, s, v);
            printf("\n");
        }
    }

    float res = closenessCentrality(graph, s, d);
    printf("\nCloseness Centrality of %d = %f\n", s, res);

    free(color);
    free(d);
    free(pi);
    return 0;
}