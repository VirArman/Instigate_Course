#include "../headers/List.hpp"
#include <iostream>
Node::Node(){}
Node::Node(int x){
    data = x;
    next = nullptr;
    previous = nullptr;
}


List::List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

// Copy constructor
List::List(const List& other){
    m_head = nullptr;
    m_size = 0;
    Node* current = other.m_head;
    while (current != nullptr){
        this->push_back(current->data);
        current = current -> next;
    }
}

List::~List(){
    Node* current = m_head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
Node* List::get_node(int n){
    Node* node = m_head;
    if(n == m_size -1){
        return m_tail;
    }
    for(int i=0;i<n;i++){
        node = node->next;
    }
    return node;
}
int List::get_size(){
    return m_size;
}

bool List::is_empty(){
    return m_head == nullptr;
}

void List::push_back(int d){
    Node* temp = new Node(d);
    temp->next = nullptr;
    if (m_head == nullptr) {
        temp->previous = nullptr;
        m_head = temp;
        m_tail = m_head;
        m_size++;
        return;
    }
    m_tail->next = temp;
    temp->previous = m_tail;
    m_tail = temp;
    m_size++;
}

void List::push_front(int d){
    Node* temp = new Node(d);            
    if(m_head == nullptr){
        m_head = m_tail = temp;
    }else{
        temp ->next = m_head;
        m_head-> previous =temp;
        m_head = temp;
    }
    m_size++;
}

void List::print(){
    Node* n = m_head;
    while (n != nullptr){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<std::endl;
}

int& List::operator[](int index){
    Node* n = m_head;
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
        push_front(d);
        return;
    }
    if(p == m_size-1){
        push_back(d);
        return;
    }
    Node* temp = m_head;
    for (int i = 0; i < p - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    newNode->previous = temp;
    newNode->next = temp->next;
    temp->next = newNode;
}

int List::remove_by_index(int pos){
    if (m_head == nullptr) {
        return -1;
    }
    Node* current = m_head;
    if (pos == 0) {
        return pop_front();
    }
    if(pos == m_size-1){
        return pop_back();
    }
    for (int i = 0; current != nullptr && i < pos - 1; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        return -1;
    }
    Node* next = current->next->next;
    int value = current->next->data;
    delete current->next;
    current->next = next;
    if (next != nullptr) {
        next->previous = current;
    }
    return value;
}

void List::remove_by_value(int value){
    if (m_head == nullptr) {
        return;
    }
    Node* temp = m_head;
    if (temp != nullptr && temp->data == value) {
        m_head = temp->next;
        m_head->previous = nullptr;
        delete temp;
        m_size--;
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
    m_size--;
}

int List::pop_back(){
    if (is_empty()) {
        throw 2;
    }

    if (m_head->next == nullptr) {
        int value = m_head -> data;
        delete m_head;
        m_head = nullptr;
        m_size--;
        return value;
    }

    int value = m_tail -> data;
    m_tail = m_tail -> previous;
    delete m_tail->next;
    m_tail->next = nullptr;
    m_size--;
    return value;
}

int List::pop_front(){
    int value = m_head->data;
    m_head = m_head -> next;
    if(m_head != nullptr){
        m_head->previous = nullptr;
    }
    delete m_head->previous;
    m_size--;
    return value;
}
