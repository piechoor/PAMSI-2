#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAX_NODE_VAL 100

class Graph {

    int edges, vertices, density;
    int** adj_matrix;

    public:
        void fillRandom();
        void showMatrix();        

        Graph(int no_vertices, float density);
        ~Graph();
};