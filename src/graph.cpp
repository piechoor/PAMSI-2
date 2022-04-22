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