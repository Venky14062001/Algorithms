#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quick_sort(int* vector_st, unsigned int vec_len)
{

    //Base Case
    if ((vec_len==0) || (vec_len==1) || (vec_len==2))
    {
        if (vec_len==2)
        {
            if (*(vector_st)>*(vector_st+1)) swap(vector_st, vector_st+1);
        }

        else {;}
    }

    else
    {
        unsigned int random_num=(unsigned int)std::rand();
        unsigned int pivot=(random_num % (vec_len));

        //Swap the first element with the pivot element
        swap(vector_st, vector_st+pivot);
        pivot=0;
        
        //Initialise the counters
        unsigned int i{0};

        for (unsigned int j=1; j<vec_len; j++)
        {
            if (*(vector_st+j)<*(vector_st))
            {
                swap(vector_st+i+1, vector_st+j);
                i++;
            }
        }

        //Swap the pivot element with the i counter
        swap(vector_st, vector_st+i);
        pivot=i;

        unsigned int len_f_h=pivot;
        unsigned int len_s_h=vec_len-pivot-1;

        //Recursive calls
        quick_sort(vector_st, len_f_h);
        quick_sort(vector_st+pivot+1, len_s_h);
    }
}

int main()
{

    std::vector<int>arr_to_sort;
    std::cout<<"Please enter the array to sort, enter a -1 to terminate"<<'\n';

    int input;
    std::srand((unsigned)std::time(0));

    do
    {
        std::cin>>input;
        if (input!=-1) {arr_to_sort.push_back(input);}
    } 
    while (input!=-1);

    unsigned int length_vector=arr_to_sort.size();

    quick_sort(&(arr_to_sort[0]), length_vector);

    std::cout<<'\n';

    std::cout<<"Printing sorted array"<<'\n';

    //Print sorted result
    for (int a: arr_to_sort)
    {
        std::cout<<a<<'\n';     
    }

}