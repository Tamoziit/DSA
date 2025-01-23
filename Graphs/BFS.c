#include <stdio.h>
#include <stdlib.h>

static int front = -1;
static int rear = -1;
static int count = 0;
int queue[100];

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
    printf("\nVertex dequeued %d\n", temp);
}

struct node
{
    int vertex;
    struct node *next;
};

struct node *createNode(int);

struct Graph
{
    int numVertices;
    struct node **adjLists;
};

struct Graph *createGraph(int vertices);

void addEdge(struct Graph *graph, int src, int dest);
void printGraph(struct Graph *graph);

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
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

void bfs(struct Graph *graph, int s, char *color, int *d, int *pi)
{
    int v;

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
    while (count != 0)
    {
        v = queue[front];
        printf("\nVertex %d\n", v);
        struct node *temp = graph->adjLists[v];
        while (temp)
        {
            if (color[temp->vertex] == 'w')
            {
                printf("\nInside if of while %d\n", temp->vertex);
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

void printpath(struct Graph *graph, int s, int v, int *pi)
{
    if (v == s)
        printf(" %d ", s);
    else if (pi[v] == -1)
        printf("No path from %d to %d exists", s, v);
    else
    {
        printpath(graph, s, pi[v], pi);
        printf(" -> %d ", v);
    }
}

int main()
{
    struct Graph *graph = createGraph(7);
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
    char color[graph->numVertices];
    int d[graph->numVertices], pi[graph->numVertices];
    int v;
    int s = 1;
    bfs(graph, s, color, d, pi);
    printf("\nVertex  Color  Distance  Predecessor\n");
    for (v = 0; v < graph->numVertices; v++)
        printf("\n  %d       %c      %d         %d\n", v, color[v], d[v], pi[v]);
    printf("\nPredecessor Subgraph\n");

    for (v = 0; v < graph->numVertices; v++)
    {
        if (v != s)
        {
            printpath(graph, s, v, pi);
            printf("\n");
        }
    }
    return 0;
}