// A class to represent a graph as a Linked List

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <algorithm>

template <typename T>
struct Node 
{
    T node_name{};
    std::vector<Node*> node_connections{};
    bool node_visited{false};

    //For Dijkstra's Algorithm
    std::vector<int> edge_lengths{}; //Same order as the node connections
    std::vector<T> shortest_path{};
    int shortest_path_length{};
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
        void addEdge(T node_1, T node_2, int edge_length);  //Modified for Dijkstra's Algorithm
        void removeNode(T node);
        Node<T>* findNode(T node);
        unsigned int getNumberVertices();
};

#endif