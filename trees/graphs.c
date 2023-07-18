#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent the graph
struct Graph
{
    int numVertices;
    int** adjacencyMatrix;
    int** incidenceMatrix;
    int* visited;
};
// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int*)malloc(vertices * sizeof(int));
    int i, j;
    for (i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize all values to 0
        }
    }

    // Allocate memory for the incidence matrix
    graph->incidenceMatrix = (int*)malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++) {
        graph->incidenceMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (j = 0; j < vertices; j++) {
            graph->incidenceMatrix[i][j] = 0; // Initialize all values to 0
        }
    }

    // Allocate memory for the visited array
    graph->visited = (int*)malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++) {
        graph->visited[i] = 0; // Initialize all values to 0
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Set the edge from source to destination
    graph->adjacencyMatrix[dest][src] = 1; // Set the edge from destination to source

    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (i == src || i == dest) {
            graph->incidenceMatrix[i][src] = 1; // Set the incidence from vertex to source
            graph->incidenceMatrix[i][dest] = 1; // Set the incidence from vertex to destination
        } else {
            graph->incidenceMatrix[i][src] = 0; // Set the incidence to 0 for other vertices
            graph->incidenceMatrix[i][dest] = 0; // Set the incidence to 0 for other vertices
        }
    }
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(struct Graph* graph,FILE *fp1) {
    fprintf(fp1,"Adjacency Matrix:\n");
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            fprintf(fp1,"%d ", graph->adjacencyMatrix[i][j]);
        }
        fprintf(fp1,"\n");
    }
}

// Function to print the incidence matrix
void printIncidenceMatrix(struct Graph* graph,FILE *fp1) {
    fprintf(fp1,"Incidence Matrix:\n");
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            fprintf(fp1,"%d ", graph->incidenceMatrix[i][j]);
        }
        fprintf(fp1,"\n");
    }
}

// Function to deallocate memory allocated for the graph
void destroyGraph(struct Graph* graph)
{
    if (graph)
        {
        if (graph->adjacencyMatrix)
        {
            int i;
            for (i = 0; i < graph->numVertices; i++)
            {
                free(graph->adjacencyMatrix[i]);
            }
            free(graph->adjacencyMatrix);
        }
        if (graph->incidenceMatrix)
        {
            int i;
            for (i = 0; i < graph->numVertices; i++)
            {
                free(graph->incidenceMatrix[i]);
            }
            free(graph->incidenceMatrix);
        }
        if (graph->visited)
        {
            free(graph->visited);
        }
        free(graph);
    }
}

// Breadth-First Search
void BFS(struct Graph* graph, int startVertex,FILE *fp1)
{
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    fprintf(fp1,"BFS Traversal: ");

    while (front < rear)
    {
        int currentVertex = queue[front++];
        fprintf(fp1,"%d ", currentVertex);

        // Enqueue all adjacent vertices of the current vertex
        int i;
        for (i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && graph->visited[i] == 0)
             {
                graph->visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    fprintf(fp1,"\n");
}

// Depth-First Search (Helper function)
void DFSUtil(struct Graph* graph, int vertex,FILE *fp1)
{
    // Mark the current vertex as visited
    graph->visited[vertex] = 1;
    fprintf(fp1,"%d ", vertex);

    // Recursively visit all the adjacent vertices of the current vertex
    int i;
    for (i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjacencyMatrix[vertex][i] == 1 && graph->visited[i] == 0)
         {
            DFSUtil(graph, i,fp1);
        }
    }
}

// Depth-First Search
void DFS(struct Graph* graph, int startVertex,FILE *fp1)
{
    fprintf(fp1,"DFS Traversal: ");
    DFSUtil(graph, startVertex,fp1);
    fprintf(fp1,"\n");
}
int main()
{
     FILE *fp=fopen("input.txt","r");
     FILE *fp1=fopen("output.txt","w");

    int numVertices, numEdges;
    fscanf(fp,"%d%d", &numVertices,&numEdges);
    struct Graph* graph = createGraph(numVertices);

    int i;
    for (i = 0; i < numEdges; i++)
    {
        int src, dest;
        printf("Enter the source and destination vertices for edge %d: ", i + 1);
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printAdjacencyMatrix(graph,fp1);
    printf("\n");
    printIncidenceMatrix(graph,fp1);
    int startVertex;
    printf("Enter the start vertex for traversal: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex,fp1);
    DFS(graph, startVertex,fp1);
    destroyGraph(graph);

    return 0;
}
