#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "constants.hh"

class Graph {
    protected:
        int edges, vertices, start_node;
        float density;

    public:
        int get_edges() {return this->edges;}

        Graph();
        Graph(int no_vertices, int start_node, float graph_density);
};