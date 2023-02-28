#include <iostream>
int main()
{
    const int SIZE = 5;
    int a[SIZE] = {};
    int resarr[SIZE-1] = {};
    std::cout<<"Insert array\n";
    for (int i = 0; i < SIZE; i++)
    {//fills array
        std::cin>>a[i];
    }
    int max = a[0];
    int indmax = 0;
    for (int i = 0; i < SIZE; i++)
    {//finds max
        if(a[i] > max)
        {
            max = a[i];
            indmax = i;
        }
    }
    for(int i = indmax; i < SIZE-1; i++)
    {//deletes max number
        a[i] = a[i+1];
    }
    for(int i = 0; i < SIZE-1; i++)
    {//Puts result in new array to show the real deleted version of array
        resarr[i] = a[i];
    }
    for(int i = 0; i < SIZE-1; i++)
    {
        std::cout<<resarr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}
