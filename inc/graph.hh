#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAX_NODE_VAL 100

struct Node {
    int dest, weight;  //dest is an idx of node
                       //weight is value of edge
    struct Node *next; //pointer to the next node
};

struct AdjList {
    struct Node *head; //head is a pointer to the node
};

class Graph {
    int edges, vertices, density;
    int** adj_matrix;
    struct AdjList *adj_list; //list consists of vertices-number
                              //of elements, idx of each indicates 
                              //node idx which we refer to

    Node* createNode(int dest_node, int weight);
    void addEdge(int src_node, int dest_node, int edge_weight);

    public:
        void fillMatrixRandom();
        void fillListRandom();
        void showMatrix();    
        void showList();    

        Graph(int no_vertices, float density);
        ~Graph();
};