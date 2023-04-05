class Array {
    private:
        //represents our array
        int* m_arr;
        //user visible size
        int m_size;
        //actual size of array
        int m_capacity;
        //changes capacity of array
        int* change_capacity();
    public:
        //Constructor without argument
        Array();
        //Constructor with size argument
        Array(int s);
        //Constructor with size and array argument
        Array(int s, int a[]);
        //Destructor
        ~Array();
        //[] operator overloading
        int& operator[](int index);
        //returns size
        int get_size();
        //pushes value at the end of array
        void push(int num);
        //adds value in specefic index
        void insert(int num, int index);
        //deletes element from specified index
        void del(int index);
        //prints defined elements of array
        void print();
};