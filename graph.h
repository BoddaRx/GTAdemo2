#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

struct edge{
    int source;
    int dist;
    int weight;
};

class Graph
{
public:
    Graph(int size);
    ~Graph();
    void add_edge(int source, int dist,int weight);
    int get_next_in_ShortestPath(int source, int dist);
private:
    int** matrix;
    int Size;
    std::vector<int> dijkstra(int source, int dist);
};

#endif // GRAPH_H
