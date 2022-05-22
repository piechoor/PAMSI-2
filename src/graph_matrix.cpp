#include "graph_matrix.hh"


Graph_Matrix::Graph_Matrix(const char *file_name) {
    std::ifstream txt_file;
    txt_file.open(file_name);
    //giving an error if the file couldnt be opened
    if(!txt_file) {
        std::cerr << "File error - file could not be opened";
        exit(1);
    }

    int temp_from, temp_to, temp_weight; //temporary variables
    this->density = 100; //arbitrary number
    this->directed = false; //file specifies that, it doesnt really matter
    // Getting basic information from a file
    txt_file >> this->edges >> this->vertices >> this->start_node;

    this->dist_arr = new int[this->vertices]; //array with distances to each node
    
    //Creating an empty 2D matrix
    this->adj_matrix = new int*[this->vertices];
    for(int i=0; i<this->vertices; ++i)
        this->adj_matrix[i] = new int[this->vertices];

    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            adj_matrix[i][j] = 0;
    }

    // adding edges as specified in a file till it ends
    while(!txt_file.eof()) {
        txt_file >> temp_from >> temp_to >> temp_weight;
        adj_matrix[temp_from][temp_to] = temp_weight;
    }
}

Graph_Matrix::Graph_Matrix(int no_vertices, int start_node, float graph_density, bool if_directed) {
    //Setting basic values
    this->edges = 0;
    this->vertices = no_vertices;
    this->start_node = start_node;
    this->density = graph_density;
    this->directed = if_directed;
    this->dist_arr = new int[no_vertices]; //array with distances to each node

    //Creating an empty matrix and setting all values to zero
    this->adj_matrix = new int*[no_vertices];
    for(int i=0; i<no_vertices; ++i)
        this->adj_matrix[i] = new int[no_vertices];
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            adj_matrix[i][j] = 0;
    }

    //Filling matrix with random values and given density
    this->fillRandom();
}


//Displays matrix in the terminal
void Graph_Matrix::display() {
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            std::cout << adj_matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void Graph_Matrix::fillRandom() {
    srand((unsigned)time(NULL));
    //determining number of nodes needed to be filled with density of the graph
    int nodesToFill = this->density*vertices*(vertices-1)/100;
    //if directed all edges are random
    if (directed) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j<this->vertices; ++j) {
                if (this->edges>=nodesToFill) break; //breaking if density is correct
                if (i==j) continue; //keeping 0 distance for identical node to node
                adj_matrix[i][j] = (rand() % MAX_NODE_VAL); //filling edge with random value
                this->edges++;
            }
        }
    }
    //if undirected edges i->j and j->i are the same
    else if (!directed) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j!=i; ++j) {
                if (this->edges>=nodesToFill) break; //breaking if density is correct
                if (i==j) continue; //keeping 0 distance for identical node to node
                adj_matrix[i][j] = (rand() % MAX_NODE_VAL); //filling edge with random value
                adj_matrix[j][i] = adj_matrix[i][j]; //adding identical edge
                this->edges+=2;
            }
        }
    }
}

void Graph_Matrix::BellmanFord() {

    //initializing distances with infinity-like value
    for (int i=0; i<this->vertices; ++i)
        this->dist_arr[i] = MAX_DIST;
    this->dist_arr[this->start_node] = 0;

    //relaxing edges vertices-1 times
    for (int k=1; k<this->vertices; ++k) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j<this->vertices; ++j) {
                if (this->dist_arr[i] + adj_matrix[i][j] < this->dist_arr[j])
                    this->dist_arr[j] = this->dist_arr[i] + adj_matrix[i][j];
            }
        }
    }
}

void Graph_Matrix::saveResults(const char *file_name) {
    std::ofstream Results(file_name, std::ios_base::app);

    for (int i=0; i<this->vertices; ++i) {
        Results << this->start_node << " -> " << i << "\tdist: " << dist_arr[i] << "\n";
    }
    Results << std::endl;

    Results.close();
}

//Destructor frees all memory allocated by a graph instance
Graph_Matrix::~Graph_Matrix() {
    for(int i=0; i<this->vertices; ++i)
        delete [] this->adj_matrix[i];
    delete [] this->adj_matrix;
    delete [] this->dist_arr;
}