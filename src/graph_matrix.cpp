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
    int nodesToFill = this->density*vertices*(vertices-1)/100;
    if (directed) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j<this->vertices; ++j) {
                if (this->edges>=nodesToFill) break;
                if (i==j) continue;
                adj_matrix[i][j] = (rand() % MAX_NODE_VAL);
                this->edges++;
            }
        }
    }
    else if (!directed) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j!=i; ++j) {
                if (this->edges>=nodesToFill) break;
                if (i==j) continue;
                adj_matrix[i][j] = (rand() % MAX_NODE_VAL);
                adj_matrix[j][i] = adj_matrix[i][j];
                this->edges+=2;
            }
        }
    }
}

int* Graph_Matrix::BellmanFord() {
    int *dist = new int[this->vertices]; //array with distances to each node
    int tempDist;

    //initializing distances with infinity-like value
    for (int i=0; i<this->vertices; ++i)
        dist[i] = MAX_DIST;
    dist[this->start_node] = 0;

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

Graph_Matrix::Graph_Matrix(const char *file_name) {
    std::ifstream txt_file;
    txt_file.open(file_name);
    if(!txt_file) {
        std::cerr << "File error - file could not be opened";
        exit(1);
    }
    int temp_from, temp_to, temp_weight;
    this->density = 100;
    this->directed = false;
    txt_file >> this->edges >> this->vertices >> this->start_node;
    this->adj_matrix = new int*[this->vertices];
    for(int i=0; i<this->vertices; ++i)
        this->adj_matrix[i] = new int[this->vertices];

    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            adj_matrix[i][j] = 0;
    }
    while(!txt_file.eof()) {
        txt_file >> temp_from >> temp_to >> temp_weight;
        adj_matrix[temp_from][temp_to] = temp_weight;
    }
}

Graph_Matrix::Graph_Matrix(int no_vertices, int start_node, float graph_density, bool if_directed) {
    this->edges = 0;
    this->vertices = no_vertices;
    this->start_node = start_node;
    this->density = graph_density;
    this->directed = if_directed;

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