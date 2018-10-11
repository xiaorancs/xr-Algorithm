/**
 *Author: xiaoran
 *Time: 2018-01-25 18:33
 *
 *Problem:
 * Dijkstra's shortest path algorithm
 */

#include <stdio.h>
#include <limits.h>

#define V 9

// 找到从初始点的v的最短距离的点
int minaDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) {
        if(sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

int printSolution(int dist[], int v) {
    printf("Vertex Distance from Source\n");
    for(int i = 0; i < v; i++) {
        printf("%d ---> %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for(int i = 0; i < V; i++) {
        int u = minaDistance(dist, sptSet);
        sptSet[u] = true;

        for(int v = 0; v < V; v++) {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(graph, 0); 
   
    return 0; 

}