class Arr {
    private:
        int* m_arr;
        int m_size;
        int m_capacity;
        //changes capacity of array
        int* change_capacity();
    public:
        //Constructor without argument
        Arr();
        //Constructor with size argument
        Arr(int s);
        //Constructor with size and array argument
        Arr(int s, int a[]);
        //Destructor
        ~Arr();
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