#pragma once

#include "graph.hh"

struct Node {
    int dest, weight;  //dest is an idx of node
                       //weight is value of edge
    struct Node *next; //pointer to the next node
};

struct AdjList {
    struct Node *head; //head is a pointer to the node
};

class Graph_List : public Graph {
    protected:
        struct AdjList *adj_list; //list consists of vertices-number
                        //of elements, idx of each indicates 
                        //node idx which we refer to

        Node* createNode(int dest_node, int weight);
        void addEdge(int src_node, int dest_node, int edge_weight);
        void fillRandom();

    public:
        void display();    
        Graph_List(int no_vertices, float graph_density);
};