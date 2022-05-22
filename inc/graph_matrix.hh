#pragma once

#include "graph.hh"

class Graph_Matrix : public Graph {
    int *dist_arr;

    protected:
        //pointer to the 2D matrix representing vertices as indexes and their
        //weights connections through values of elements of proper index
        int** adj_matrix;

    public:
        Graph_Matrix(const char *file_name); //creates graph from a specified file
        Graph_Matrix(int no_vertices, int start_node, float graph_density, bool if_directed);
        
        void fillRandom(); //filling list with random values
        void display(); //displays adjacency list
        void BellmanFord(); //shortest path algorithm
        int* get_distances() {return this->dist_arr;} //returns pointer to the distances array
        void saveResults(const char *file_name); //saving distances array to a file

        ~Graph_Matrix();
};