#pragma once

#include "graph.hh"

class Graph_Matrix : public Graph {
    protected:
        int** adj_matrix;
        void fillRandom();

    public:
        void display();   
        int* BellmanFord(int rel_node);
        Graph_Matrix(int no_vertices, float graph_density);
        ~Graph_Matrix();
};