#include <iostream>
#include "dyn_arr.cpp"
int* insertion_sort(int* arr, int len);

//int main()
//{
//  int len = 5;
//  int* a = create_arr(len);
//  a = insertion_sort(a, len);
//  print_arr(a,len);
//}

int* insertion_sort(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return arr;
}
