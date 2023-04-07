#include <iostream>
#include "Array.hpp"
#include <cassert>
int main(){
// Test default constructor
    Array arr;
    assert(arr.get_size() == 0);
// Test constructor with size parameter
    Array arr1(5);
    assert(arr1.get_size() == 5);
    for(int i = 0; i < arr1.get_size(); i++){
        arr1[i] = i+1;
    }
// Test copy constructor
    Array arr2 = arr1;
    assert(arr2.get_size() == 5);
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
// Test assignment, == and != operators
    arr2 = arr;
    assert((arr2 == arr) == true);
    assert((arr2 != arr1) == true);
// Test insert method
    arr.insert(5, 1);
    assert(arr[0] == 1);
    assert(arr[1] == 5);
    assert(arr[2] == 2);
    assert(arr[3] == 3);
    assert(arr[4] == 4);
// Test delete method
    arr.del(1);
    for(int i = 0; i < arr.get_size(); i++){
        assert(arr[i] == i+1);
    }
    // Test out-of-bounds access
    try {
        arr[5];
        assert(!"out of bounds did not work");  // should not reach this line
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
