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

void bubble_sort(std::vector<int>& array_to_sort)
{
    unsigned int len_array=array_to_sort.size();

    while (true)
    {
        bool swapped=false;

        for (unsigned int i=1; i<len_array; i++)
        {
            if (array_to_sort[i]<array_to_sort[i-1]) {swap(&(array_to_sort[i-1]), &(array_to_sort[i])); swapped=true;}
        }

        if (!swapped) {break;}
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

    bubble_sort(arr_to_sort);

    std::cout<<"Printing sorted array"<<'\n';

    //Print sorted result
    for (int a: arr_to_sort)
    {
        std::cout<<a<<'\n';
    }

}