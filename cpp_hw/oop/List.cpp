#include "List.hpp"
#include <iostream>
Node::Node(){}
Node::Node(int x){
    data = x;
    next = nullptr;
}

List::List(){
    first = nullptr;
}

int List::get_size(){
    Node* tmp = first;
    int size = 0;
    if(is_empty()){
        return 0;
    }
    while (tmp != nullptr){
        tmp = tmp->next;
        size++;
    }
    return size;
}

bool List::is_empty(){
    return first == nullptr;
}

void List::push_back(int d){
   Node* temp = new Node(d);
   if(is_empty()){
        first = temp;
   }else{
        Node* n = first;
        while (n->next != nullptr){
            n = n->next;
        }
        n->next = temp;
   }
}

void List::print(){
    Node* n = first;
    while (n != nullptr){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<std::endl;
}