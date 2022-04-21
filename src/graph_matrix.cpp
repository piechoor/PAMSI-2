#include "graph_matrix.hh"


void Graph_Matrix::display() {
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            std::cout << adj_matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void Graph_Matrix::fillRandom() { 
    this->edges=0;
    srand((unsigned)time(NULL));
    int nodesToFill = this->density*vertices*(vertices-1)/200, nodesFilled=0;
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j, ++nodesFilled) {
            if (nodesFilled>nodesToFill) break;
            adj_matrix[i][j] = (rand() % MAX_NODE_VAL);
            this->edges++;
        }
    }
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j) {
            adj_matrix[j][i] = adj_matrix[i][j];
            this->edges++;
        }
    }
}

Graph_Matrix::Graph_Matrix(int no_vertices, float graph_density) {
    this->edges = 0;
    this->vertices = no_vertices;
    this->density = graph_density;

    this->adj_matrix = new int*[no_vertices];
    for(int i=0; i<no_vertices; ++i)
        this->adj_matrix[i] = new int[no_vertices];

    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            adj_matrix[i][j] = 0;
    }
    this->fillRandom();
}


Graph_Matrix::~Graph_Matrix() {
    for(int i=0; i<this->vertices; ++i)
        delete [] this->adj_matrix[i];
    delete [] this->adj_matrix;
}