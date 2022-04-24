#include "graph.hh"

Graph::Graph() {
    this->edges=0;
    this->vertices=0;
    this->start_node=0;
    this->density=0;
}

Graph::Graph(int no_vertices, int start_node, float graph_density) {
    this->edges = 0;
    this->vertices = no_vertices;
    this->start_node = start_node;
    this->density = graph_density;
}