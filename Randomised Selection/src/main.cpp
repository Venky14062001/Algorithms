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

int random_selection(int* vector_st, unsigned int vec_len, unsigned int ele_pos)
{

    //Base Case
    if (vec_len==1)
    {
        return  (*vector_st); 
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

        int ele_op;

        //Check if the pivot is greater or smaller than the element to be found
        if (pivot<ele_pos) ele_op=random_selection(vector_st+pivot+1, len_s_h, ele_pos-pivot-1);

        else if (pivot>ele_pos) ele_op=random_selection(vector_st, len_f_h, pivot);

        else return *(vector_st+pivot);

        return ele_op;
    }
}

int main()
{

    std::vector<int>arr_to_sort;
    int ele_op;
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

    std::cout<<"Please enter the position element needed"<<'\n';
    unsigned int pos_ip;

    std::cin>>pos_ip;

    ele_op=random_selection(&(arr_to_sort[0]), length_vector, pos_ip);

    std::cout<<'\n';

    std::cout<<"Printing element in the position"<<'\n';
    std::cout<<ele_op<<'\n';

}