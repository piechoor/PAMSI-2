#include <iostream>
#include "test_algorithms.hh"
#include "graph_list.hh"

//TODO
//gestosc grafow floaat/int? procenty/ulamek?
//destruktor do list
//listy jednokierunkowe


int main() {
    // graph_sizes[0] must be a number of the following sizes
    int graph_sizes[] = {5, 10, 25, 50, 75, 100};
    //graph_densities[0] must be a number of the following desities
    int graph_densities[] = {4, 25, 50, 75, 100};
    if(!test(graph_sizes, graph_densities)) return 0;

    // Graph_List g(5, 0, 25, false);
    // g.display();
    // g.BellmanFord();
    return 0;
}