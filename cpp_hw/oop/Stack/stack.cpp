#include "../headers/stack.hpp"

Stack::Stack(){
    top = nullptr;
}

void Stack::push(int value){
    stack.push_front(value);
    top = stack.get_node(0);
}

void Stack::pop(){
    stack.remove_by_index(0);
    top = stack.get_node(0);
}

int Stack::peek(){
    return top->data;
}

int Stack::get_size(){
    return stack.get_size();
}

bool Stack::is_empty(){
    return stack.is_empty();
}