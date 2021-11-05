#include <iostream>
#include <cmath>
#include <string>
#include <vector>

void insertion_sort(std::vector<int>& array_to_sort)
{
    unsigned int len_array=array_to_sort.size();

    for (unsigned int i=1; i<len_array; i++)
    {

        int arr_element=array_to_sort[i];
        int j=(int) i-1;

        while (j>=0 && array_to_sort[(unsigned int)j]>arr_element)
        {
            array_to_sort[(unsigned int)j+1]=array_to_sort[(unsigned int)j];
            j--;
        }

        array_to_sort[(unsigned int)j+1]=arr_element;
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

    insertion_sort(arr_to_sort);

    std::cout<<"Printing sorted array"<<'\n';

    //Print sorted result
    for (int a: arr_to_sort)
    {
        std::cout<<a<<'\n';
    }

}