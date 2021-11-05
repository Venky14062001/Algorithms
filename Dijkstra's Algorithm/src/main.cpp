#include "linkedList.h"

template <typename T>
void dijkstra_algo(Graph<T> graph_input, T start_node, std::vector<Node<T>*>& nodes_visited)
{
    int no_of_nodes=(int) graph_input.getNumberVertices();

    Node<T>* start_node_ptr=graph_input.findNode(start_node);

    start_node_ptr->node_visited=true;
    (start_node_ptr->shortest_path).push_back(start_node_ptr->node_name);
    start_node_ptr->shortest_path_length=0;
    nodes_visited.push_back(start_node_ptr);

    for (int i=0; i<no_of_nodes-1; i++)
    {
        int smallest_edge;
        Node<T>* node_to_add;
        Node<T>* prev_node;
        bool first_iter=true;

        for (unsigned int j=0; j<nodes_visited.size(); j++)
        {
            for (unsigned int k=0; k<(nodes_visited[j]->node_connections).size(); k++)
            {
                if (!(((nodes_visited[j]->node_connections)[k])->node_visited))
                {
                    if (first_iter)
                    {
                        smallest_edge=(nodes_visited[j]->shortest_path_length)+((nodes_visited[j]->edge_lengths)[k]);
                        node_to_add=(nodes_visited[j]->node_connections)[k];
                        prev_node=nodes_visited[j];
                        first_iter=false;
                    }  

                    else if (((nodes_visited[j]->shortest_path_length)+(nodes_visited[j]->edge_lengths)[k])<smallest_edge)
                    {
                        smallest_edge=(nodes_visited[j]->shortest_path_length)+((nodes_visited[j]->edge_lengths)[k]);
                        node_to_add=(nodes_visited[j]->node_connections)[k];
                        prev_node=nodes_visited[j];
                    } 
                }
            }
        }

        node_to_add->node_visited=true;
        node_to_add->shortest_path_length=smallest_edge;
        std::copy((prev_node->shortest_path).begin(), (prev_node->shortest_path).end(), std::back_inserter(node_to_add->shortest_path));
        (node_to_add->shortest_path).push_back(node_to_add->node_name);
        nodes_visited.push_back(node_to_add);
    }

    std::cout<<"Dijkstra's algorithm completed execution!"<<'\n';
}

int main()
{
    Graph<int> g{4};
    g.readGraph();
    std::vector<Node<int>*> nodes_visited{};

    dijkstra_algo(g, 1, nodes_visited);

    std::cout<<"Printing shortest length between 1 and 4"<<'\n';
    auto a =g.findNode(4);
    std::cout<<a->shortest_path_length<<'\n';

    std::cout<<"Printing shortest path between 1 and 4"<<'\n';
    for (auto i: a->shortest_path)
    {
        std::cout<<i<<"->";
    }
    std::cout<<"Goal Reached"<<'\n';

    return 0;
}