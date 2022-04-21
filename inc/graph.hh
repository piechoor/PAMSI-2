#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAX_NODE_VAL 100
#define AS_INFINITY 9*MAX_NODE_VAL

class Graph {
    protected:
        int edges, vertices, density;

    public:
        int get_edges() {return this->edges;}   
        void BellmanFord_Matrix(int rel_node);

        Graph();
        Graph(int no_vertices, float graph_density);
};