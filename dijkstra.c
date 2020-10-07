#include <stdio.h>
#include<string.h>
#define INFINITY 9999
#define MAX 10
void Dijkstra(int Graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];
    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1) {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    for (i = 0; i < n; i++)
        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    printf("\n");
}
void addEdge(int Graph[MAX][MAX], int u, int v, int weight) {
    Graph[u][v] = weight;
    Graph[v][u] = weight;
}
int main() {
    int ch, u, v, vertices, weight;
    printf("Enter the number of vertices in the Graph:");
    scanf("%d", & vertices);
    int Graph[MAX][MAX];
    memset(Graph, 0, vertices * vertices * sizeof(int));
    do {
        printf("Select any one:\n1. Add an Edge\n2. Find the shortest path\n3. Exit\n");
        printf("Enter your selection:");
        scanf("%d", & ch);
        switch (ch) {
        case 1:
            printf("Enter vertices along which edge will be added(starts at 0)(u,v):");
            scanf("%d %d", & u, & v);
            printf("Enter the weight of edge:");
            scanf("%d", & weight);
            addEdge(Graph, u, v, weight);
            break;
        case 2:
            printf("Enter starting vertex:");
            scanf("%d", & u);
            Dijkstra(Graph, vertices, u);
            break;
        }
    } while (ch != 3);
    return 0;
}
