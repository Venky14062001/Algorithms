#include <iostream>
#include <cmath>
#include <string>
#include <vector>

std::vector<int> merge_sort(std::vector<int>& array_to_sort)
{

    unsigned int len_array=array_to_sort.size();

    //Base case
    if (len_array==1)
    {
        return array_to_sort;
    }

    else
    {
        std::vector<int> sorted_arr;
  
        std::vector<int> l_half(array_to_sort.begin(), array_to_sort.begin()+(len_array/2));
        std::vector<int> r_half(array_to_sort.begin()+(len_array/2), array_to_sort.end());

        std::vector<int> l=merge_sort(l_half);
        std::vector<int> r=merge_sort(r_half);

        unsigned int i{0};
        unsigned int j{0};
        unsigned int l_size=l.size();
        unsigned int r_size=r.size();

        for(unsigned int k=0; k<len_array; k++)
        {
            if ((i==l_size) || (j==r_size))
            {
                if (i==l_size)
                {
                    std::copy(r.begin()+j, r.end(), std::back_inserter(sorted_arr));
                    break;
                }

                else
                {
                    std::copy(l.begin()+i, l.end(), std::back_inserter(sorted_arr));
                    break;
                }
            }

            else if (l[i]<r[j])
            {
                sorted_arr.push_back(l[i]);
                i++;
            }

            else if (r[j]<l[i])
            {
                sorted_arr.push_back(r[j]);
                j++;
            }

            else if (l[i]==r[j])
            {
                sorted_arr.push_back(l[i]);
                sorted_arr.push_back(r[j]);
                i++; j++;
            }
        }

        return sorted_arr;
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

    std::vector<int>sorted_array=merge_sort(arr_to_sort);

    std::cout<<"Printing sorted array"<<'\n';

    //Print sorted result
    for (int a: sorted_array)
    {
        std::cout<<a<<'\n';
    }

}