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

void List::push_front(int d){
    Node* temp = new Node(d);
    temp->next = first;
    first =temp;
}

void List::print(){
    Node* n = first;
    while (n != nullptr){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<std::endl;
}

int& List::operator[](int index){
    Node* n = first;
    int count = 0;
    while (n != nullptr){
        if(count == index){
            return n->data;
        }
        n = n->next;
        count++;
    }
    throw 1;
}

void List::insert(int d, int p){
    Node* temp = new Node(d);
    Node* n = first;
    int count = 0;
    if(p == 0){
        push_front(d);
    }
    while (n != nullptr){
        if(count == p-1){
            temp->next = n->next;
            n->next = temp;
        }
        n = n->next;
        count++;
    }
}