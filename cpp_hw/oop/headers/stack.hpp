#include <iostream>
#include "List.hpp"

class Stack{
    private:
    List stack;
    Node* top;
    public:
    //default constructor
    Stack();
    //adds number in stack and reassignes top
    void push(int x);
    //Removes top value of stack
    void pop();
    //gets top element without deleting
    int peek();
    //shows count of elements in stack
    int get_size();
    //shows if there element in stack or not
    bool is_empty();
};