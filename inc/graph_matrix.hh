#pragma once

#include "graph.hh"

class Graph_Matrix : public Graph {
    protected:
        int** adj_matrix;
        void fillRandom();

    public:
        void display();
        int* BellmanFord();
        Graph_Matrix(const char *file_name);
        Graph_Matrix(int no_vertices, int start_node, float graph_density, bool if_directed);
        ~Graph_Matrix();
};