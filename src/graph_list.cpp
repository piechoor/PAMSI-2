#include "graph_list.hh"

Node* Graph_List::createNode(int dest_node, int weight) {
    Node *newNode = new Node;
    newNode->dest = dest_node;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void Graph_List::addEdge(int src_node, int dest_node, int edge_weight) {
    Node *newNode = createNode(dest_node, edge_weight);
    newNode->next = adj_list[src_node].head;
    adj_list[src_node].head = newNode;
    this->edges++;
    // DODAJE SYMETRYCZNE ELEMENTY
    // newNode = createNode(src_node, edge_weight);
    // newNode->next = adj_list[dest_node].head;
    // adj_list[dest_node].head = newNode;
}

void Graph_List::fillRandom() {
    this->edges=0;
    srand((unsigned)time(NULL));
    int nodesToFill = this->density*vertices*(vertices-1)/100;
    int common_val;
    if (directed) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j<this->vertices; ++j) {
                if (this->edges>=nodesToFill) break;
                if (i==j) continue;
                addEdge(i,j,(rand() % MAX_NODE_VAL));
            }
        }
    }
    else if (!directed) {
        for (int i=0; i<this->vertices; ++i) {
            for (int j=0; j!=i; ++j) {
                if (this->edges>=nodesToFill) break;
                common_val = rand() % MAX_NODE_VAL;
                addEdge(i,j,common_val);
                addEdge(j,i,common_val);
            }
        }
    }
}

void Graph_List::display() {
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

Graph_List::Graph_List(const char *file_name) {
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

    this->adj_list = new AdjList[this->vertices];
    std::cout << "VERT: " << this->vertices << "\n";
    for (int i=0; i<this->vertices; ++i)
        adj_list[i].head = NULL;

    while(!txt_file.eof()) {
        txt_file >> temp_from >> temp_to >> temp_weight;
        addEdge(temp_from, temp_to, temp_weight);
    }
}

Graph_List::Graph_List(int no_vertices, int start_node, float graph_density, bool if_directed) {
    this->edges = 0;
    this->vertices = no_vertices;
    this->start_node = start_node;
    this->density = graph_density;
    this->directed = if_directed;
    
    this->adj_list = new AdjList[this->vertices];
    std::cout << "VERT: " << this->vertices << "\n";
    for (int i=0; i<this->vertices; ++i)
        adj_list[i].head = NULL;

    this->fillRandom();
}

int* Graph_List::BellmanFord() {
    int *dist = new int[this->vertices]; //array with distances to each node
    int tempDist;

    //initializing distances with infinity-like value
    for (int i=0; i<this->vertices; ++i)
        dist[i] = MAX_DIST;
    dist[this->start_node] = 0;

    //relaxing edges vertices-1 times
    for (int i=0; i<this->vertices; ++i) {
        Node* ptrNode = adj_list[i].head;
        //int j=0;
        while (ptrNode) {
            //if (i==j) continue;
            if (dist[i] + ptrNode->weight < dist[ptrNode->dest])
                dist[ptrNode->dest] = dist[i] + ptrNode->weight;
            ptrNode = ptrNode->next;
            //++j;
        }
    }
    return dist;
}