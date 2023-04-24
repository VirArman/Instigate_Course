#include "../headers/List.hpp"
#include <iostream>
Node::Node(){}
Node::Node(int x){
    data = x;
    next = nullptr;
    previous = nullptr;
}


List::List() : m_first(nullptr), m_size(0) {}

// Copy constructor
List::List(const List& other){
    m_first = nullptr;
    Node* current = other.m_first;
    while (current != nullptr){
        this->push_back(current->data);
        current = current -> next;
    }
}

List::~List(){
    Node* current = m_first;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
Node* List::get_node(int n){
    Node* node = m_first;
    for(int i=0;i<n;i++){
        node = node->next;
    }
    return node;
}
int List::get_size(){
    return m_size;
}

bool List::is_empty(){
    return m_first == nullptr;
}

void List::push_back(int d){
    Node* temp = new Node(d);
    temp->next = nullptr;
    if (m_first == nullptr) {
        temp->previous = nullptr;
        m_first = temp;
        return;
    }
    Node* last = m_first;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = temp;
    temp->previous = last;
}

void List::push_front(int d){
    Node* temp = new Node(d);
    temp->next = m_first;
    if (m_first != nullptr) {
        m_first->previous = temp;
    }
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
    Node* newNode = new Node(d);
    if (p == 0) {
        newNode->previous = nullptr;
        newNode->next = m_first;
        if (m_first != nullptr) {
            m_first->previous = newNode;
        }
        m_first = newNode;
        return;
    }
    Node* temp = m_first;
    for (int i = 0; i < p - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    newNode->previous = temp;
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->previous = newNode;
    }
    temp->next = newNode;
}

int List::remove_by_index(int pos){
    if (m_first == nullptr) {
        return -1;
    }
    Node* current = m_first;
    if (pos == 0) {
        m_first = current->next;
        if (m_first != nullptr) {
            m_first->previous = nullptr;
        }
        delete current;
        return 0;
    }
    for (int i = 0; current != nullptr && i < pos - 1; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        return -1;
    }
    Node* next = current->next->next;
    delete current->next;
    current->next = next;
    if (next != nullptr) {
        next->previous = current;
    }
    return -1;
}

void List::remove_by_value(int value){
    if (m_first == nullptr) {
        return;
    }
    Node* temp = m_first;
    if (temp != nullptr && temp->data == value) {
        m_first = temp->next;
        m_first->previous = nullptr;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return;
    }
    temp->previous->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->previous = temp->previous;
    }
    delete temp;
}

int List::pop_back(){
        if (is_empty()) {
            throw 2;
        }

        if (m_first->next == nullptr) {
            int value = m_first -> data;
            delete m_first;
            m_first = nullptr;
            return value;
        }

        Node* curr = m_first;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        int value = curr -> data;
        delete curr->next;
        curr->next = nullptr;
        m_size--;
        return value;
}