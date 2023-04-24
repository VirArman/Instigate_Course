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
        //Copy constructor that copies array element by element
        Array(const Array &other);
        //Destructor
        ~Array();
        //Checks equality of two arrays by comparing element by element and by size
        bool operator==(const Array& other);
        //Checks inequality of two arrays by comparing element by element and by size
        bool operator!=(const Array& other);
        //Assignes array element by element
        Array& operator=(const Array& other);
        //[] operator overloading, get elemen of array by specefied index
        int& operator[](int index);
        //returns visible size of array
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