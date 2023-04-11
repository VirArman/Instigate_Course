class Node{
    public:
        int data;
        Node* next;
//constructor with argument
        Node();
        Node(int x);
};
class List{
    public:
        Node* first;
//constructor without argument assignes null to first node
        List();
//counts nodes of lists and returnes
        int get_size();
//checks if list is epmty or not
        bool is_empty();
//adds node with specefic value at the end of the list
        void push_back(int data);
//prints elements of list
        void print();
};
