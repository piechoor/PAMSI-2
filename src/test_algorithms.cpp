#include "test_algorithms.hh"

int test(int *sizes, int* densities) {
    testFile();
    for (int i=1; i<=sizes[0]; ++i) {
        for (int j=1; j<=densities[0]; ++j) {
            Graph_Matrix newGraphM(sizes[i], START_NODE, densities[j], IS_DIRECTED);
            auto t_start = std::chrono::steady_clock::now();
            for (int k=0; k<NO_GRAPHS_TESTED; ++k) {
                Graph_Matrix newGraphM(sizes[i], START_NODE, densities[j], IS_DIRECTED);
                //newGraphM.fillRandom();
                newGraphM.BellmanFord();
            }
            auto t_end = std::chrono::steady_clock::now();
            auto duration_t = t_end - t_start;
            float sortTime = std::chrono::duration <double> (duration_t).count();
            std::cout << "MATRIX:\t SIZE: " << sizes[i] << " DENSITY: " << densities[j] << " TIME: " << 1000*sortTime/NO_GRAPHS_TESTED << "\n";
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
    for (int i=1; i<=sizes[0]; ++i) {
        for (int j=1; j<=densities[0]; ++j) {
            Graph_List newGraphL(sizes[i], START_NODE, densities[j], IS_DIRECTED);
            auto t_start = std::chrono::steady_clock::now();
            for (int k=0; k<NO_GRAPHS_TESTED; ++k) {
                Graph_List newGraphL(sizes[i], START_NODE, densities[j], IS_DIRECTED);
                //newGraphL.fillRandom();
                newGraphL.BellmanFord();
            }
            auto t_end = std::chrono::steady_clock::now();
            auto duration_t = t_end - t_start;
            float sortTime = std::chrono::duration <double> (duration_t).count();
            std::cout << "LIST:\t SIZE: " << sizes[i] << " DENSITY: " << densities[j] << " TIME: " << 1000*sortTime/NO_GRAPHS_TESTED << "\n";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

void testFile() {
///////IDENTYCZNY GRAF Z PLIKU
//POROWNANIE ALGORYTMU DLA LISTY I MACIERZY SASIEDZTWA
    Graph_List gl("graph1.txt");
    Graph_Matrix gm("graph1.txt");
    gl.BellmanFord(); int *arrL = gl.get_distances();
    gm.BellmanFord(); int *arrM = gm.get_distances();
    std::cout << "Odleglosci lista: ";
    for (int i=0; i<gl.get_vertices(); ++i)
        std::cout<<arrL[i]<<"\t";
    gl.saveResults(RESULTS_FILE);
    std::cout << "Odleglosci macierz: ";
    for (int i=0; i<gm.get_vertices(); ++i)
        std::cout<<arrM[i]<<"\t";
    gm.saveResults(RESULTS_FILE);
    std::cout << std::endl;
}