#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAX_NODE_VAL 100
#define MAX_DIST 9*MAX_NODE_VAL

class Graph {
    protected:
        int edges, vertices, density;

    public:
        int get_edges() {return this->edges;}

        Graph();
        Graph(int no_vertices, float graph_density);
};