#include <iostream>
int* create_arr(int);
void print_arr(int*,int);
///
//int main()
//{
//   int n;
//   std::cout<<"Insert size of array \n";
//   std::cin>>n;
//   int* a = create_arr(n);
//   print_arr(a,n);
//   delete [] a;
//   std::cout<<std::endl;
//}

int* create_arr(int n)
{
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        std::cin>>*(arr+i);
    }
    return arr;
}
void print_arr(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout<<*(arr+i)<<" ";
    }    
   std::cout<<std::endl;
}

