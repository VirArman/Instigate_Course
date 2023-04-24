class Node{
    public:
        int data;
        Node* next;
        Node* previous;
        //constructor without argument
        Node();
        //constructor with argument
        Node(int x);
};
class List{
    private:
        //keeps size of the list
        int m_size;
        //keeps address of the first node
        Node* m_first;
    public:
        //constructor without argument assignes null to first node
        List();

        //Copy constructor takes element of "other" and pushes it at back of new List
        List(const List& other);

        //Iterates through nodes and deletes one by one
        ~List();

        //returnes Node of specified index
        Node* get_node(int);

        //returnes m_size;
        int get_size();

        //checks if list is epmty or not
        bool is_empty();

        //adds node with specefic value at the end of the list
        void push_back(int data);

        //adds node at start of the list
        void push_front(int data);

        //prints elements of list
        void print();

        //Iterates through list untill getting to "index" and return original value of the Node
        int& operator[] (int index);

        //adds node at the specefic position by traversing the list
        void insert(int data, int position);

        //removes by traversing list untill "index" position
        int remove_by_index(int index);

        //removes by traversing list untill finding Node with value of "data"
        void remove_by_value(int data);
        
        //removes the last node of list and returnes value of that node
        int pop_back();
};
