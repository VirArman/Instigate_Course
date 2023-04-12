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
        List();//done
        //counts nodes of lists and returnes
        int get_size();//done
        //checks if list is epmty or not
        bool is_empty();//done
        //adds node with specefic value at the end of the list
        void push_back(int data);//done
        void push_front(int data);//done
        //prints elements of list
        void print();//done
        int& operator[] (int index);//done
        void insert(int data, int position);//done
        void remove_by_index(int index);
        void remove_by_value(int data);
        void pop_back();
};
