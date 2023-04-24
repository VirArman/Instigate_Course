#include "../headers/stack.hpp"

Stack::Stack(){
    top = 0;
}

void Stack::push(int value){
    stack.insert(value,0);
    top = value;
}

int Stack::pop(){
    int value = top;
    stack.del(0);
    top = stack[0];
    return value;
}

int Stack::peek(){
    return top;
}

int Stack::get_size(){
    return stack.get_size();
}

bool Stack::is_empty(){
    return stack.get_size() == 0;
}