#include <iostream>
#include "insertion_sort.cpp"
int binary_search(int* arr, int l, int r, int x);
int main()
{
    int* a = {new int[]{12,11,25,78,56,24,23,13,15}};
    a = insertion_sort(a,9);
    print_arr(a,9);
    int ans = binary_search(a,0,8,15);
    std::cout<<"The index is "<<ans<<std::endl;
}
int binary_search(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
 
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}
