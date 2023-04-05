class Arr {
    private:
        int* m_arr = nullptr;
        int m_size = 0;
        int m_capacity = 4;
        int* change_capacity();
    public:
        Arr();
        Arr(int s);
        Arr(int s, int a[]);
        ~Arr();
        int& operator[](int index);
        int len();
        void push(int num);
        void insert(int num, int index);
        void del(int index);
        void print();
};