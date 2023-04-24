#include "Array.hpp"

class Stack{
    private:
    Array stack;
    int top;
    public:
    //default constructor
    Stack();
    //adds number in stack and reassignes top
    void push(int x);
    //Removes top value of stack
    int pop();
    //gets top element without deleting
    int peek();
    //shows count of elements in stack
    int get_size();
    //shows if there element in stack or not
    bool is_empty();
};