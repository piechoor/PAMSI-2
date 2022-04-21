#include "graph.hh"

Graph::Graph() {
    this->edges=0;
    this->vertices=0;
    this->density=0;
}

Graph::Graph(int no_vertices, float graph_density) {
    this->edges = 0;
    this->vertices = no_vertices;
    this->density = graph_density;
}


void Graph::BellmanFord_Matrix(int rel_node) {

    int dist[this->vertices]; //array with distances to each node
    //initializing distances with infinity-like value
    for (int i=0; i<this->vertices; ++i)
        dist[i] = AS_INFINITY;
    dist[rel_node] = 0;

    //relaxing edges vertices-1 times
    for (int i=1; i <=this->vertices; ++i) {
            for (int j=0; j<this->edges; j++) {
                // int u = graph->edge[j].src;
                // int v = graph->edge[j].dest;
                // int weight = graph->edge[j].weight;
                // if (dist[u] != INT_MAX
                //     && dist[u] + weight < dist[v])
                //     dist[v] = dist[u] + weight;
            }
        }
}
