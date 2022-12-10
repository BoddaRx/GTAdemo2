#include "graph.h"


Graph::Graph(int size)

{
    Size = size;
    matrix = new int*[size];
    for(int i=0;i<size;i++)
        matrix[i] = new int[size];

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            matrix[i][j] = 0;
}
Graph::~Graph()
{
    for(int i=0;i<Size;i++)
        delete[] matrix[i];

    delete[] matrix;
}
void Graph::add_edge(int source, int dist,int weight)
{
    matrix[source][dist] = weight;
    matrix[dist][source] = weight;

}
int Graph::get_next_in_ShortestPath(int source, int dist)
{
    std::vector<int> path = dijkstra(source,dist);
    return path.at(0)-source;
    //-1 means left
    //1 means right
    // >1 means down
    // <-1 means up
}

#include <limits.h>
int minDistance(int* dist, bool* visited, int size)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++)
        if (!visited[v] && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}
std::vector<int> Graph::dijkstra(int src, int dist)
{
    int distances[Size];
    int predecessors[Size];
    bool visited[Size];
    for (int i = 0; i < Size; i++)
    {distances[i] = INT_MAX;
    visited[i] = false;}

    distances[src] = 0;
    predecessors[src] = -1;

    for (int count = 0; count < Size - 1; count++) {
        int u = minDistance(distances, visited,Size);

        visited[u] = true;
        for (int v = 0; v < Size; v++)
            if (!visited[v] && matrix[u][v] !=0
                && distances[u] != INT_MAX
                && distances[u] + matrix[u][v] < distances[v])
            {
                predecessors[v] = u;
                distances[v] = distances[u] + matrix[u][v];
            }
    }
    std::vector<int> path;
    int p = dist;
    while(p!=src)
    {
        path.insert(path.begin()+0,p);
        p = predecessors[p];
    }
    return path;

}


