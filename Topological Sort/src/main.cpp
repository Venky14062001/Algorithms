#include "directedGraphLinkedList.h"
#include <cstdlib>
#include <map>

template <typename T>
void depth_first_search(Node<T>* start_vertex, std::map<T, int>& topological_order, int& counter)
{
    start_vertex->node_visited=true;
    unsigned int no_of_edges=start_vertex->node_connections.size();

    for (unsigned int j=0; j<no_of_edges; j++)
    {
        if (!((start_vertex->node_connections[j])->node_visited))
        {
            (start_vertex->node_connections[j])->node_visited=true;
            depth_first_search(start_vertex->node_connections[j], topological_order, counter);
        }
    }

    counter--;
    topological_order.insert({start_vertex->node_name, counter});
}

template <typename T>
std::map<T, int> topological_sort(Graph<T> graph_input)
{
    unsigned int no_of_vertices=graph_input.getNumberVertices();
    std::map<T, int>topological_order;

    int counter=no_of_vertices;

    for (unsigned int i=0; i<no_of_vertices; i++)
    {
        Node<T>* current_vertex=graph_input.graph[i];

        if (!current_vertex->node_visited)
        {
            depth_first_search(current_vertex, topological_order, counter);
        }
    }
}

int main()
{
    return 0;
}