#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

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

static int front = -1;
static int rear = -1;
static int count = 0;
int queue[MAXROWS];

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

void printQueue()
{
    int i;
    printf("The BFS Queue\n");
    for (i = front; i <= rear; i++)
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

void bfs(Graph *graph, char *color, int *d, int *pi, int s)
{
    int v;
    printf("\nStarting BFS\n");

    // Initial state
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

    // BFS starts
    while (count != 0)
    {
        v = queue[front]; // vertex to be explored
        printf("Exploring vertex: %d\n", v);
        printQueue();

        Node *temp = graph->adjList[v];
        while (temp)
        {
            if (color[temp->vertex] == 'w')
            {
                color[temp->vertex] = 'g';  // discovered
                d[temp->vertex] = d[v] + 1; // 1 level up from predecessor
                pi[temp->vertex] = v;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }

        dequeue();      // vertex v fully explored, so dequeuing it from exploration bfs queue
        color[v] = 'b'; // fully explored
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
    bfs(graph, color, d, pi, s); // starting BFS from source 's'

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

    free(color);
    free(d);
    free(pi);
    return 0;
}