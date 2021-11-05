//Uses an Edge list representation for the graph

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <string>
#include <vector>
#include <tuple>
#include <array>

std::vector<std::array<int, 3>> get_vertices_and_edges(int no_vertices)
{
    std::vector<std::array<int, 3>> ret_obj;

    std::cout<<"Start entering the vertices connected to each edge for all the edges, enter -1 and -1 for both the vertices if all the edges are entered"<<'\n';
    std::cout<<"There should be atleast n-1 edges, where n is number of vertices"<<'\n';

    int edge_count{};
    int vertex_1{}; 
    int vertex_2{};
    std::array<int, 3> temp_array{};

    do 
    {
        std::cout<<"Enter vertices for edge number "<<edge_count+1<<'\n';
        std::cin>>vertex_1;
        std::cin>>vertex_2;

        if ((vertex_1 != -1) && (vertex_2 != -1))
        {
            temp_array[0]=++edge_count;
            temp_array[1]=std::min(vertex_1, vertex_2);
            temp_array[2]=std::max(vertex_1, vertex_2);
            ret_obj.push_back(temp_array);
        }
    }

    while (((vertex_1 != -1) && (vertex_2 != -1)) || (edge_count<no_vertices-1));

    return ret_obj;
}

void print_graph(const std::vector<std::array<int, 3>> &graph_ip)
{
    unsigned int edge_size=graph_ip.size();

    for (unsigned int i=0; i<edge_size; i++)
    {
        std::cout<<"Printing edge number "<<i+1<<" and its connecting vertices are:"<<'\n';
        std::cout<<graph_ip[i][1]<<'\n';
        std::cout<<graph_ip[i][2]<<'\n';
    }

    std::cout<<"Completed printing the graph"<<'\n';
}

bool is_two_vertices(const std::vector<std::array<int, 3>> &graph_ip)
{
    unsigned int edge_size=graph_ip.size();
    int prev_vertex_1=graph_ip[0][1];
    int prev_vertex_2=graph_ip[0][2];

    for (unsigned int i=1; i<edge_size-1; i++)
    {
        int curr_vertex_1=graph_ip[i][1];
        int curr_vertex_2=graph_ip[i][2];

        if ((prev_vertex_1!=curr_vertex_1) || (prev_vertex_2!=curr_vertex_2))
        {
            return false;
        }

        else {;}

        prev_vertex_1=curr_vertex_1;
        prev_vertex_2=curr_vertex_2;
    }

    return true;
}

int random_contraction(const std::vector<std::array<int, 3>> &graph_ip)
{
    unsigned int edge_size=graph_ip.size();

    bool base_case=is_two_vertices(graph_ip);

    std::vector<std::array<int, 3>> updated_graph{graph_ip};

    int min_cut{};

    if (base_case) return (int)edge_size;

    else
    {
        unsigned int random_num=(unsigned int)std::rand();
        unsigned int random_edge=(random_num % (edge_size));

        //Get the vertices attached to the selected edge and contract the vertices into a single node
        int selected_vertex_1=graph_ip[random_edge][1];
        int selected_vertex_2=graph_ip[random_edge][2];

        //Remove the element containing the edge chosen
        auto position=updated_graph.begin()+random_edge;
        updated_graph.erase(position);

        std::array<int, 3> temp_array{};
        unsigned int iter{0};
        unsigned int j{0};

        //Iterate through the vector and change the edge connections
        while (j<edge_size-1)
        {
            int curr_vertex_1=updated_graph[iter][1];
            int curr_vertex_2=updated_graph[iter][2];

            //If its a self loop, delete it
            if ((curr_vertex_1==selected_vertex_1) && (curr_vertex_2==selected_vertex_2))
            {
                auto position=updated_graph.begin()+iter;
                updated_graph.erase(position);
                j++;
            }

            else if ((curr_vertex_1==selected_vertex_1) || (curr_vertex_1==selected_vertex_2))
            {
                temp_array[0]=(int)iter+1;
                temp_array[1]=selected_vertex_1;
                temp_array[2]=curr_vertex_2;
                updated_graph[iter]=temp_array;
                iter++; j++;
            }

            else if ((curr_vertex_2==selected_vertex_1) || (curr_vertex_2==selected_vertex_2))
            {
                temp_array[0]=(int)iter+1;
                temp_array[1]=selected_vertex_1;
                temp_array[2]=curr_vertex_1;
                updated_graph[iter]=temp_array;
                iter++; j++;
            }

            else
            {
                temp_array[0]=(int)iter+1;
                temp_array[1]=curr_vertex_1;
                temp_array[2]=curr_vertex_2;
                updated_graph[iter]=temp_array;
                iter++; j++;
            }
        }

    }

    min_cut=random_contraction(updated_graph);

    return min_cut;
}

int main()
{
    int no_vertices{};
    int min_cut{100000};

    std::cout<<"Enter the number of vertices in the graph"<<'\n';
    std::cin>>no_vertices;

    std::vector<std::array<int, 3>> graph_ip=get_vertices_and_edges(no_vertices);

    //We run the algorithm (n^2)*(ln n) times to bring the probability of failure down to 1/n
    int no_times=(int)(std::pow(no_vertices, 2))*(std::log(no_vertices));
    int min_cut_temp;

    for (int i=0; i<no_times; i++)
    {
        min_cut_temp=random_contraction(graph_ip);
        if (min_cut_temp<min_cut) min_cut=min_cut_temp;
    }

    std::cout<<"The minimum number of cuts are: "<<min_cut<<'\n';  
}