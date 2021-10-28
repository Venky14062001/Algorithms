#include <iostream>
#include <cmath>
#include <string>

int karatsuba(std::string a, std::string b)
{

    auto len_a=a.length();
    auto len_b=b.length();

    //Ensure the length of strings are the same
    if(len_a!=len_b)
    {
        if(len_a<len_b)
        {
            auto diff=len_b-len_a;
            a.insert(a.begin(), diff, '0');
        }

        else
        {
            auto diff=len_a-len_b;
            b.insert(b.begin(), diff, '0');
        }
    }

    //Base case
    if (len_a==1)
    {
        return (std::stoi(a)*std::stoi(b));
    }

    else
    {
        auto length=a.length();

        int l=karatsuba(a.substr(0, (length/2)), b.substr(0, (length/2)));

        int r=karatsuba(a.substr((length/2), length-1), b.substr((length/2), length-1));


        int lr=karatsuba(std::to_string(std::stoi(a.substr(0, (length/2)))+std::stoi(a.substr((length/2), length-1))), 
        std::to_string(std::stoi(b.substr(0, (length/2)))+std::stoi(b.substr((length/2), length-1))));

        int lr_diff=lr-l-r;

        return ((l*std::pow(10, (length+(length % 2))))+(lr_diff*std::pow(10, (length/2+(length % 2))))+(r));
    }
}

int main()
{
    std::string a, b;
    int result;
    std::cout<<"Enter the first number to multiply"<<'\n';
    std::cin>>a;
    std::cout<<"Enter the second number to multiply"<<'\n';
    std::cin>>b;

    result=karatsuba(a, b);
    std::cout<<"Result is: "<<result<<'\n';
}