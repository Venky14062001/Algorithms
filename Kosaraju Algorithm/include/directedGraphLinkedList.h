// A class to represent a graph as a Linked List

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>

template <typename T>
struct Node 
{
    T node_name{};
    std::vector<Node*> node_connections{};
    bool node_visited{false};

    //For Kosaraju Algorithm
    std::vector<Node*> reverse_node_connections{};
    bool reverse_node_visited{false};
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

        //For Kosaraju Algorithm
        void reverseGraph(); //Fills the reverse_node_connections vector with the reverse graph
        void printReverseGraph();
};

#endif