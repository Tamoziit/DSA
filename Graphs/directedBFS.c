#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

static int rear = -1;
static int front = -1;
static int count = 0;
int queue[MAXROWS];

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
    if(rear == 0)
        front = 0;
    count++;
}

void dequeue()
{
    front++;
    count--;
}

void printQueue()
{
    int i;
    printf("The Queue: ");
    for(i=front; i<=rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
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

void directedBfs(Graph *graph, int s, char *color, int *d, int *pi)
{
    int v;
    printf("\nEvaluating BFS\n");
    Node *temp;

    for(v=0; v< graph->numVertices; v++)
    {
        if(v != s)
        {
            color[v] = 'w';
            d[v] = 9999; // inf.
            pi[v] = -1;
        }
    }
    color[s] = 'g';
    d[s] = 0;
    pi[s] = -1;
    enqueue(s);

    while(count != 0)
    {
        v = queue[front];
        printf("Exploring vertex: %d\n", v);
        printQueue();
        
        temp = graph->adjList[v];
        while(temp)
        {
            if(color[temp->vertex] == 'w')
            {
                color[temp->vertex] = 'g';
                d[temp->vertex] = d[v] + 1;
                pi[temp->vertex] = v;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
        color[v] = 'b';
        dequeue();
    }
}

void printPath(Graph *graph, int s, int v, int *pi)
{
    if(v == s)
        printf(" %d ", s);
    else if(pi[v] == -1)
        printf("No path from %d to %d exists", s, v);
    else
    {
        printPath(graph, s, pi[v], pi);
        printf(" -> %d ", v);
    }
}

int main()
{
    int n, s;
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

    char *color = (char *)malloc(n * sizeof(char));
    int *d = (int *)malloc(n * sizeof(int));
    int *pi = (int *)malloc(n * sizeof(int));

    printf("\nEnter source for BFS:\n");
    scanf("%d", &s);
    int v;
    directedBfs(graph, s, color, d, pi);

    printf("\nVertex  Color  Distance  Predecessor\n");
    for (v = 0; v < graph->numVertices; v++)
        printf("\n  %d       %c      %d         %d\n", v, color[v], d[v], pi[v]);
    printf("\nPredecessor Subgraph\n");
    for(v = 0; v< graph->numVertices; v++)
    {
        if(v != s)
        {
            printPath(graph, s, v, pi);
            printf("\n");
        }
    }

    free(color);
    free(d);
    free(pi);
    return 0;
}