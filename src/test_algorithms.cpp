#include "test_algorithms.hh"

int test(int *sizes, int* densities) {
    // for (int i=1; i<=sizes[0]; ++i) {
    //     for (int j=1; j<=densities[0]; ++j) {
    //         Graph_List newGraphL(sizes[i], START_NODE, densities[j], false);
    //         Graph_Matrix newGraphM(sizes[i], START_NODE, densities[j], false);
    //         newGraphL.BellmanFord();
    //         newGraphM.BellmanFord();
    //         std::cout << "EDGES LIST: " << newGraphL.get_edges() << " SIZE: " << sizes[i] << " DENS " << densities[j] << std::endl;
    //         std::cout << "EDGES MATRIX: " << newGraphM.get_edges() << " SIZE: " << sizes[i] << " DENS " << densities[j] << std::endl << std::endl;
    //     }
    // }
    // return 0;
    Graph_List gl("graph1.txt");
    Graph_Matrix gm("graph1.txt");
    int *arrL=gl.BellmanFord();
    int *arrM=gm.BellmanFord();
    std::cout << "Odleglosci lista: ";
    for (int i=0; i<GRAPH_SIZE; ++i)
        std::cout<<arrL[i]<<"\t";
    std::cout << "Odleglosci macierz: ";
    for (int i=0; i<GRAPH_SIZE; ++i)
        std::cout<<arrM[i]<<"\t";
    
}