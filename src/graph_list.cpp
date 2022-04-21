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
    newNode = createNode(src_node, edge_weight);
    newNode->next = adj_list[dest_node].head;
    adj_list[dest_node].head = newNode;
}

void Graph_List::fillRandom() {
    //int test_nodesFilled;
    this->edges=0;
    srand((unsigned)time(NULL));
    int nodesToFill = this->density*vertices*(vertices-1)/200, nodesFilled=0;
    for (int i=0; i<this->vertices; ++i) {
        for (int j=0; j!=i; ++j, ++nodesFilled) {
            if (nodesFilled>nodesToFill) break;
            addEdge(i,j,(rand() % MAX_NODE_VAL));
            this->edges+=2;
            //test_nodesFilled++;
        }
    }
    //std::cout<<"Nodes filled " << test_nodesFilled << std::endl;
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

Graph_List::Graph_List(int no_vertices, float graph_density) {
    this->edges = 0;
    this->vertices = no_vertices;
    this->density = graph_density;
    
    this->adj_list = new AdjList;
    for (int i=0; i<this->vertices; ++i)
        adj_list[i].head = NULL;

    this->fillRandom();
}