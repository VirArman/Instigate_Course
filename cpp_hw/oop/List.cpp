#include "List.hpp"
#include <iostream>
Node::Node(){}
Node::Node(int x){
    data = x;
    next = nullptr;
}


List::List() : m_first(nullptr), m_size(0) {}

// Copy constructor
List::List(const List& other) {
    m_first = new Node(other.m_first->data);
    Node* current = m_first;
    Node* other_current = other.m_first->next;
    while (other_current != nullptr) {
        current->next = new Node(other_current->data);
        current = current->next;
        other_current = other_current->next;
    }
}

List::~List() {
    Node* current = m_first;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int List::get_size(){
    return m_size;
}

bool List::is_empty(){
    return m_first == nullptr;
}

void List::push_back(int d){
   Node* temp = new Node(d);
   if(is_empty()){
        m_first = temp;
        m_size++;
   }else{
        Node* n = m_first;
        while (n->next != nullptr){
            n = n->next;
        }
        n->next = temp;
        m_size++;
   }
}

void List::push_front(int d){
    Node* temp = new Node(d);
    temp->next = m_first;
    m_first = temp;
    m_size++;
}

void List::print(){
    Node* n = m_first;
    while (n != nullptr){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<std::endl;
}

int& List::operator[](int index){
    Node* n = m_first;
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
    Node* n = m_first;
    int count = 0;
    if(p == 0){
        push_front(d);
    }
    while (n != nullptr){
        if(count == p-1){
            temp->next = n->next;
            n->next = temp;
            m_size++;
            return;
        }
        n = n->next;
        count++;
    }
}

int List::remove_by_index(int pos){
    if(m_size == 0){
        throw 2;
    }
    if(pos >= m_size && pos < 0){
        throw 1;
    }
    if(pos == m_size-1){
        pop_back();
    }
    int count = 0;
    Node* temp;
    Node* n = m_first;
    while(n != nullptr){
        if(count == pos-1){
            temp = n -> next;
            n -> next = n -> next -> next;
        }
        n = n -> next;
        count++;
    }
    int deleted = temp->data;
    delete temp;
    m_size--;
    return deleted;
}

void List::remove_by_value(int value){
    Node* temp;
    Node* n = m_first;
    Node* prev;
    while(n != nullptr){
        if(n->data == value){
            temp = n;
            prev -> next = n -> next;    
            delete temp;
            m_size--;
            return;
        }
        prev = n;
        n = n -> next;
    }
    throw 3;
}
int List::pop_back(){
        if (m_first == NULL) {
            throw 1;
        }

        if (m_first->next == NULL) {
            int value = m_first -> data;
            delete m_first;
            m_first = NULL;
            return value;
        }

        Node* curr = m_first;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }
        int value = curr -> data;
        delete curr->next;
        curr->next = NULL;
        m_size--;
        return value;
}