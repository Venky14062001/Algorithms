#include <iostream>
#include <cmath>
#include <string>
#include <vector>

void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(std::vector<int>& array_to_sort)
{
    unsigned int len_array=array_to_sort.size();

    for (unsigned int i=0; i<len_array-1; i++)
    {
        unsigned int min_element_position=i;

        for (unsigned int j=i+1; j<len_array; j++)
        {
            if (array_to_sort[j]<array_to_sort[min_element_position]) {min_element_position=j;}
        }

        swap(&(array_to_sort[i]), &(array_to_sort[min_element_position]));
    }
}

int main()
{

    std::vector<int>arr_to_sort;
    std::cout<<"Please enter the array to sort, enter a -1 to terminate"<<'\n';

    int input;

    do
    {
        std::cin>>input;
        if (input!=-1) {arr_to_sort.push_back(input);}
    } 
    while (input!=-1);

    selection_sort(arr_to_sort);

    std::cout<<"Printing sorted array"<<'\n';

    //Print sorted result
    for (int a: arr_to_sort)
    {
        std::cout<<a<<'\n';
    }

}