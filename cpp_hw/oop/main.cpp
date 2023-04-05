#include <iostream>
#include "smart_array.hpp"
#include <cassert>
#include <stdexcept>
int main(){
// Test default constructor
    Array arr;
    assert(arr.get_size() == 0);
// Test constructor with size parameter
    Array arr1(5);
    assert(arr1.get_size() == 5);
// Test constructor with size and array parameter
    int a[3] = {1, 2, 3};
    Array arr2(3, a);
    assert(arr2.get_size() == 3);
    for(int i = 0; i < arr2.get_size(); i++){
        assert(arr2[i] == i+1);
    }
// Test push method
    for(int i = 0; i < 4; i++){
        arr.push(i + 1);
    }
    assert(arr.get_size() == 4);
    for(int i = 0; i < arr.get_size(); i++){
        assert(arr[i] == i+1);
    }
// Test insert method
    arr.insert(5, 1);
    assert(arr.get_size() == 5);
    assert(arr[0] == 1);
    assert(arr[1] == 5);
    assert(arr[2] == 2);
    assert(arr[3] == 3);
    assert(arr[4] == 4);
// Test delete method
    arr.del(1);
    assert(arr.get_size() == 4);
    for(int i = 0; i < arr.get_size(); i++){
        assert(arr[i] == i+1);
    }
    // Test out-of-bounds access
    try {
        arr[5];
        assert(false);  // should not reach this line
    }
    catch (int e) {
        assert(true);
    }

    // Test negative index access
    try {
        arr[-1];
        assert(false);  // should not reach this line
    }
    catch (int e) {
        assert(true);
    }

    // Test invalid size parameter
    try {
        Array arr3(-1);
        assert(false);  // should not reach this line
    }
    catch (int e) {
        assert(e == 2);
    }

    // Test invalid index parameter
    try {
        arr.insert(5, -1);
        assert(false);  // should not reach this line
    }
    catch (int e) {
        assert(e == 1);
    }

    // Test invalid index parameter
    try {
        arr.insert(5, 5);
        assert(false);  // should not reach this line
    }
    catch (int e) {
        assert(e == 1);
    }
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
