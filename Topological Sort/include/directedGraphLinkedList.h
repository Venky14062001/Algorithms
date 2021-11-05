// A class to represent a graph as a Linked List

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

template <typename T>
struct Node 
{
    T node_name{};
    std::vector<Node*> node_connections{};
    bool node_visited{false};
    int layer_number{};
};

template <typename T>
class Graph
{
    private:
        unsigned int no_vertices{};
    
    public:
        std::vector<struct Node<T>*> graph{};
        Graph(unsigned int vertices_count);
        void printGraph();
        void readGraph();
        void addNode();
        void addEdge(T node_1, T node_2);
        void removeNode(T node);
        Node<T>* findNode(T node);
        int getNumberVertices();
};

#endif