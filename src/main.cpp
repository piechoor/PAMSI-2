#include <iostream>
#include "graph_list.hh"
#include "graph_matrix.hh"

int main() {
    int size=4;
    Graph_Matrix newGraph(size,100);
    newGraph.display();
    std::cout << "number of edges: " << newGraph.get_edges() << std::endl;
    int* arr = newGraph.BellmanFord(0);
    std::cout << "Odleglosci: ";
    for (int i=0; i<size; ++i)
        std::cout<<arr[i]<<"\t";
    return 0;
}