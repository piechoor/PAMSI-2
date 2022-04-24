#include <iostream>
#include "test_algorithms.hh"


//TODO
//gestosc grafow floaat/int? procenty/ulamek?

int main() {
    //graph_sizes[0] must be a number of the following sizes
    int graph_sizes[] = {5, 10, 50, 100, 500, 1000};
    //graph_densities[0] must be a number of the following desities
    int graph_densities[] = {4, 25, 50, 75, 100};
    if(!test(graph_sizes, graph_densities)) return 0;
    return 0;
}