#include "directedGraphLinkedList.h"

template <typename T>
Graph<T>::Graph(unsigned int vertices_count): no_vertices{vertices_count}
{
    std::cout<<"Graph has been declared with "<<no_vertices<<" count"<<'\n';
}

template <typename T>
void Graph<T>::readGraph()
{
    std::cout<<"Enter the connections to each vertex when prompted"<<'\n';

    for (unsigned int i=0; i<no_vertices; i++)
    {
        std::cout<<"Enter the name for vertex number "<<i<<'\n';
        T vertex_name;
        std::cin>>vertex_name;

        graph.push_back(new (struct Node<T>));
        graph[i]->node_name=vertex_name;
    }

    for (unsigned int j=0; j<graph.size(); j++)
    {
        std::cout<<"Enter the number of nodes connecting to the vertex: "<<graph[j]->node_name<<'\n';
        unsigned int no_of_connections;
        std::cin>>no_of_connections;

        T connecting_vertex;
        int edge_length;
        
        for (unsigned int k=0; k<no_of_connections; k++)
        {
            std::cout<<"Enter the name of number "<<k+1<<" node connecting to the vertex: "<<graph[j]->node_name<<'\n';
            std::cin>>connecting_vertex;
            std::cout<<"Enter the edge length between "<<graph[j]->node_name<<" and "<<connecting_vertex<<'\n';
            std::cin>>edge_length;
            addEdge(graph[j]->node_name, connecting_vertex, edge_length);
        }
    }
}

template <typename T>
void Graph<T>::printGraph()
{
    for (auto i=graph.begin(); i!=graph.end(); ++i)
    {
        std::cout<<"Printing the connections for vertex "<<((*i)->node_name)<<'\n';
        std::cout<<(*i)->node_name;

        //Modified for Dijkstra's Algorithm
        for (unsigned int j=0; j<((*i)->node_connections).size(); j++)
        {
            std::cout<<"--(";
            std::cout<<((*i)->edge_lengths)[j];
            std::cout<<")-->";
            std::cout<<(((*i)->node_connections)[j])->node_name;
        }

        std::cout<<'\n';
    }

    std::cout<<"------------------------------------------------";
    std::cout<<'\n';
}

template <typename T>
void Graph<T>::addNode()
{
    std::cout<<"Enter the name for vertex number"<<no_vertices<<'\n';

    T vertex_name;
    std::cin>>vertex_name;

    Node<T>* new_vertex=new struct Node<T>;
    new_vertex->node_name=vertex_name;

    graph.push_back(new_vertex);
    no_vertices++;
    std::cout<<"Node "<<vertex_name<<" added to the graph!"<<'\n';
}

//Modified for Dijkstra's Algorithm
template <typename T>
void Graph<T>::addEdge(T node_1, T node_2, int edge_length)
{
    bool node_1_found=false;
    bool node_2_found=false;
    Node<T>* node_1_ptr;
    Node<T>* node_2_ptr;

    for (auto i: graph)
    {
        if ((i->node_name)==node_1) 
        {
            node_1_found=true;
            node_1_ptr=i;
        }
        
        else if ((i->node_name)==node_2)
        {
            node_2_found=true;
            node_2_ptr=i;
        }  
    }

    if ((node_1_found==false) || (node_2_found==false)) 
    {
        std::cout<<"The nodes are not present in the current graph size"<<'\n';
        return;
    }

    (node_1_ptr->node_connections).push_back(node_2_ptr);
    //Modified for Dijkstra's Algorithm
    (node_1_ptr->edge_lengths).push_back(edge_length);
}

template <typename T>
void Graph<T>::removeNode(T node)
{
    std::vector<Node<T>*>temp;

    for (unsigned int i=0; i<graph.size(); i++)
    {
        if (graph[i]->node_name==node)
        {
            temp=graph[i]->node_connections;
            auto j=graph.begin()+i;
            graph.erase(j);
            break;
        }
    }

    for (unsigned int l=0; l<graph.size(); l++)
    {
        for (unsigned int m=0; m<(graph[l]->node_connections).size(); m++)
        {
            //Modified for Dijkstra's Algorithm
            if (((graph[l]->node_connections)[m])->node_name==node) 
            {
                auto n=(graph[l]->node_connections).begin()+m;
                auto l=(graph[l]->edge_lengths).begin()+m;
                (graph[l]->node_connections).erase(n);
                (graph[l]->edge_lengths).erase(l);
            }
        }
    }

    //Iterate over temp and remove the node
    for (auto k: temp)
    {
        for (unsigned int j=0; j<(k->node_connections).size(); j++)
        {
            //Modified for Dijkstra's Algorithm
            if ((k->node_connections)[j]->node_name==node) 
            {
                auto position_2=(k->node_connections).begin()+j;
                auto position_2_ed=(k->edge_lengths).begin()+j;
                (k->node_connections).erase(position_2);
                (k->edge_lengths).erase(position_2_ed);
            }
        }
    }

    no_vertices--;
}

template <typename T>
Node<T>* Graph<T>::findNode(T node)
{
    for (auto i: graph)
    {
        if (i->node_name==node) return i;
    }

    std::cout<<"Node "<<node<<" not found in the graph"<<'\n';
    return nullptr;
}

template <typename T>
unsigned int Graph<T>::getNumberVertices()
{
    return no_vertices;
}