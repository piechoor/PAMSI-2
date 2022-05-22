#include <iostream>
#include "test_algorithms.hh"
#include "graph_list.hh"


int main() {
    // graph_sizes[0] must be a number of the following sizes
    int graph_sizes[] = {5, 50, 100, 150, 200, 250};
    //graph_densities[0] must be a number of the following desities
    int graph_densities[] = {4, 25, 50, 75, 100};
    if(test(graph_sizes, graph_densities)) return 1;

    return 0;
}