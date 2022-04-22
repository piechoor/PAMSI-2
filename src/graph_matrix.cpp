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
            this->edges+=2;
        }
    }
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j)
            adj_matrix[j][i] = adj_matrix[i][j];
    }
}

int* Graph_Matrix::BellmanFord(int rel_node) {
    int *dist = new int[this->vertices]; //array with distances to each node
    int tempDist;

    //initializing distances with infinity-like value
    for (int i=0; i<this->vertices; ++i)
        dist[i] = MAX_DIST;
    dist[rel_node] = 0;

    //relaxing edges vertices-1 times
    for (int i=0; i <this->vertices; ++i) {
        for (int j=0; j <this->vertices; ++j) {
            if (i==j) continue;
            if (dist[i] + adj_matrix[i][j] < dist[j])
                dist[j] = dist[i] + adj_matrix[i][j];
        }
    }
    return dist;
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
    adj_matrix[0][3]=1;
    adj_matrix[3][0]=1;
    adj_matrix[3][2]=6;
    adj_matrix[2][2]=6;
    adj_matrix[0][2]=66;
    adj_matrix[2][0]=66;
}


Graph_Matrix::~Graph_Matrix() {
    for(int i=0; i<this->vertices; ++i)
        delete [] this->adj_matrix[i];
    delete [] this->adj_matrix;
}