#include <cassert>
template <typename V>
class Node{
    public:
        V data;
        Node* next;
        Node* previous;
        //constructor without argument
        Node(){};
        //constructor with argument
        Node(V x){
            data = x;
            next = nullptr;
            previous = nullptr;
        }
};
template <typename T>
class List{
    private:
        //keeps size of the list
        int m_size;
        //keeps address of the first Node
        Node<T>* m_head;
        Node<T>* m_tail;
    public:
        //constructor without argument assignes null to first node
        List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        //Copy constructor takes element of "other" and pushes it at back of new List
        List(const List& other){
            m_head = nullptr;
            m_size = 0;
            Node<T>* current = other.m_head;
            while (current != nullptr){
                this->push_back(current->data);
                current = current -> next;
            }
        }
        //Iterates through nodes and deletes one by one
        ~List(){
            Node<T>* current = m_head;
            while (current != nullptr) {
                Node<T>* temp = current;
                current = current->next;
                delete temp;
            }
        }
        //returnes Node of specified index
        Node<T>* get_node(int n){
            Node<T>* node = m_head;
            if(n == m_size -1){
                return m_tail;
            }
            for(int i=0;i<n;i++){
                node = node->next;
            }
            return node;
        }

        //returnes m_size;
        int get_size(){
            return m_size;
        }

        //checks if list is epmty or not
        bool is_empty(){
            return m_head == nullptr;
        }

        //adds node with specefic value at the end of the list
        void push_back(T d){
            Node<T>* temp = new Node<T>(d);
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

        //adds node at start of the list
        void push_front(T d){
            Node<T>* temp = new Node<T>(d);            
            if(m_head == nullptr){
                m_head = m_tail = temp;
            }else{
                temp ->next = m_head;
                m_head-> previous =temp;
                m_head = temp;
            }
            m_size++;
        }

        //prints elements of list
        void print(){
            Node<T>* n = m_head;
            while (n != nullptr){
                std::cout<<n->data<<" ";
                n = n->next;
            }
            std::cout<<std::endl;
        }

        //Iterates through list untill getting to "index" and return original value of the Node
        T& operator[](int index){
            assert(index < m_size || index >= m_size);
            Node<T>* n = m_head;
            int count = 0;
            while (n != nullptr){
                if(count == index){
                    return n->data;
                }
                n = n->next;
                count++;
            }
        }

        //adds node at the specefic position by traversing the list
        void insert(T d, int p){
            assert(!(p < 0 || p > m_size));
            Node<T>* newNode = new Node<T>(d);
            if (p == 0) {
                push_front(d);
                return;
            }
            if(p == m_size){
                push_back(d);
                return;
            }
            Node<T>* temp = m_head;
            for (int i = 0; i < p - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            newNode->previous = temp;
            newNode->next = temp->next;
            temp->next = newNode;
        }

        //removes by traversing list untill "index" position
        T remove_by_index(int pos){
            assert(!(pos < 0 || pos >= m_size));
            assert(m_head != nullptr);
            Node<T>* current = m_head;
            if (pos == 0) {
                return pop_front();
            }
            if(pos == m_size-1){
                return pop_back();
            }
            for (int i = 0; current != nullptr && i < pos - 1; i++) {
                current = current->next;
            }
            
            Node<T>* next = current->next->next;
            T value = current->next->data;
            delete current->next;
            current->next = next;
            if (next != nullptr) {
                next->previous = current;
            }
            return value;
        }

        //removes by traversing list untill finding Node with value of "data"
        void remove_by_value(T value){
            if (m_head == nullptr) {
                return;
            }
            Node<T>* temp = m_head;
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
            assert(temp != nullptr);
            temp->previous->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->previous = temp->previous;
            }
            delete temp;
            m_size--;
        }

        //removes the last node of list and returnes value of that node
        T pop_back(){
            assert(!is_empty());

            if (m_head->next == nullptr) {
                T value = m_head -> data;
                delete m_head;
                m_head = nullptr;
                m_size--;
                return value;
            }

            T value = m_tail -> data;
            m_tail = m_tail -> previous;
            delete m_tail->next;
            m_tail->next = nullptr;
            m_size--;
            return value;
        }
        //removes the first node of list and returnes value of that node
        T pop_front(){            
            assert(is_empty());
            T value = m_head->data;
            m_head = m_head -> next;
            if(m_head != nullptr){
                m_head->previous = nullptr;
            }
            delete m_head->previous;
            m_size--;
            return value;
        }
        //Turning list backwords
        void reverse(){
            Node<T>* current_node = m_head;
            while (current_node != NULL) {
                Node<T>* temp_node = current_node->next;
                current_node->next = current_node->previous;
                current_node->previous = temp_node;
                m_head = current_node;
                current_node = temp_node;
            }
        }
};
