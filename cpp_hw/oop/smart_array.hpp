class Arr {
    private:
        int* m_arr;
        int m_size;
        int m_capacity;
        int* copy(){}
    public:
        Arr(){}
        Arr(int s){}
        Arr(int s, int a[]){}        
        ~Arr(){}
        int& operator[](int index){}
        int len() {}
        void push(int num){}        
        void insert(int num, int index){}
        void del(int index){}
        void print(){}
};