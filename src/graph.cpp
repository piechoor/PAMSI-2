#include "graph.hh"


Node* Graph::createNode(int dest_node, int weight) {
    Node *newNode = new Node;
    newNode->dest = dest_node;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void Graph::addEdge(int src_node, int dest_node, int edge_weight) {
    Node *newNode = createNode(dest_node, edge_weight);
    newNode->next = adj_list[src_node].head;
    adj_list[src_node].head = newNode;
    newNode = createNode(src_node, edge_weight);
    newNode->next = adj_list[dest_node].head;
    adj_list[dest_node].head = newNode;
}

void Graph::fillMatrixRandom() { 
    //int test_nodesFilled=0;
    srand((unsigned)time(NULL));
    int nodesToFill = this->density*vertices*(vertices-1)/200, nodesFilled=0;
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j, ++nodesFilled) {
            if (nodesFilled>nodesToFill) break;
            adj_matrix[i][j] = (rand() % MAX_NODE_VAL);
        }
    }
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j)
            adj_matrix[j][i] = adj_matrix[i][j];
    }
    // for (int i=0; i<this->vertices; ++i) {
    //     for (int j=0; j<this->vertices; ++j) {
    //         if (adj_matrix[i][j]!=0) 
    //             test_nodesFilled++;
    //     }
    // }
    // std::cout<<"Nodes filled " << test_nodesFilled << std::endl;
}

void Graph::fillListRandom() {
    //int test_nodesFilled;
    srand((unsigned)time(NULL));
    int nodesToFill = this->density*vertices*(vertices-1)/200, nodesFilled=0;
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j, ++nodesFilled) {
            if (nodesFilled>nodesToFill) break;
            addEdge(i,j,(rand() % MAX_NODE_VAL));
            //test_nodesFilled++;
        }
    }
    //std::cout<<"Nodes filled " << test_nodesFilled << std::endl;
}

void Graph::showMatrix() {
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j<this->vertices; ++j)
            std::cout << adj_matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void Graph::showList() {
    for (int i=0; i<this->vertices; ++i) {
        Node* ptrNode = adj_list[i].head;
        std::cout << "Node " << i << ".\t";
        while (ptrNode) {
            std::cout << "->" << ptrNode->dest << "[W=" 
                      << ptrNode->weight << "]";
            ptrNode = ptrNode->next;
        }
        std::cout << std::endl;
    }
}

Graph::Graph(int no_vertices, float graph_density) {
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
    
    this->adj_list = new AdjList;
    for (int i=0; i<this->vertices; ++i)
        adj_list[i].head = NULL;

    this->fillMatrixRandom();
    this->fillListRandom();
}

Graph::~Graph() {
    for(int i=0; i<this->vertices; ++i)
        delete [] this->adj_matrix[i];
    delete [] this->adj_matrix;
}