#include "directedGraphLinkedList.h"

template <typename T>
void depth_first_search_fp(Node<T>* start_vertex, std::vector<Node<T>*>& node_finish_order)
{
    start_vertex->reverse_node_visited=true;
    unsigned int no_of_edges=start_vertex->reverse_node_connections.size();

    for (unsigned int j=0; j<no_of_edges; j++)
    {
        if (!((start_vertex->reverse_node_connections[j])->reverse_node_visited))
        {
            (start_vertex->reverse_node_connections[j])->reverse_node_visited=true;
            depth_first_search_fp(start_vertex->reverse_node_connections[j], node_finish_order);
        }
    }

    node_finish_order.push_back(start_vertex);
}

template <typename T>
void depth_first_search_sp(Node<T>* start_vertex, std::map<int, std::vector<int>>& leader_node_list, T node_name)
{
    start_vertex->node_visited=true;
    unsigned int no_of_edges=start_vertex->node_connections.size();

    for (unsigned int j=0; j<no_of_edges; j++)
    {
        if (!((start_vertex->node_connections[j])->node_visited))
        {
            (start_vertex->node_connections[j])->node_visited=true;
            depth_first_search_sp(start_vertex->node_connections[j], leader_node_list, node_name);
        }
    }

    leader_node_list[node_name].push_back(start_vertex->node_name);
}

int main()
{
    Graph<int> g{9};
    g.readGraph();

    //Node finish order
    std::vector<Node<int>*> node_finish_order{};

    for (auto i: g.graph)
    {
        auto start_vertex=i;
        depth_first_search_fp(start_vertex, node_finish_order);
    }

    //Vector of leader nodes, the first element is the leader node, followed by the other nodes connected to it in the SCC
    std::map<int, std::vector<int>>leader_node_list;
    
    for (auto j=node_finish_order.end()-1; j>=node_finish_order.begin(); j--)
    {
        auto start_vertex=(*j);
        leader_node_list.insert({(*j)->node_name, {}});
        depth_first_search_sp(start_vertex, leader_node_list, (*j)->node_name);
    }

    //Print the result
    for (auto a: leader_node_list)
    {
        std::cout<<"Leader node: "<<a.first<<'\n';
        for (auto b: a.second)
        {
            std::cout<<b<<'\n';
        }

        std::cout<<"--------------------------------------"<<'\n';
    }

    return 0;
}