#include <iostream>
class Arr {
    private:
        int* m_arr = nullptr;
        int m_size = 0;
        int m_capacity = 4;

        int* copy()
        {
            m_capacity = m_size * 1.5;
            int* narr = new int[m_capacity]{0};
            for (int i = 0; i < m_size; i++){
                narr[i] = m_arr[i];  
            }
            delete [] m_arr;
            return narr;
        }

    public:
        Arr(){
            m_arr = new int[m_capacity]{0};
        }
        Arr(int s){
            try{
                if(s <= 0){
                    throw 2;
                }
                m_size = s;
                m_capacity = m_size * 1.5;
                m_arr = new int[m_capacity]{0};
            }catch(int err){
                if(err == 2){
                    std::cout<<"The size must be bigger than 0"<<"\n";
                }
            }
        }
        Arr(int s, int a[]){
            try{
                if(s <= 0){
                    throw 2;
                }
                m_size = s;
                m_capacity = m_size * 1.5;
                m_arr = new int[m_capacity]{0};
                for(int i = 0; i < m_size; i++){
                    m_arr[i] = a[i];
                }
            }catch(int err){
                if(err == 2){
                    std::cout<<"The size must be bigger than 0"<<"\n";
                }
            }
        }        
        ~Arr(){
            delete [] m_arr;
        }
        int& operator[](int index){
            try{
                if (index < 0 || index >= m_size) {
                    throw 1;
                }   
                return m_arr[index];
            }catch(int err)
            {
                if(err == 1){
                    std::cout << "Array index out of bound"<<"\n";
                }
            }
        }
        int len()
        {
            return m_size;
        }
        void push(int num){
            //adds number at the end of Array
            m_size++;
            if(m_size == m_capacity){
                m_arr = copy();
            }
            m_arr[m_size-1] = num;
        }
        void insert(int num, int index){//Bug in case of inserting at the end of array
            //adds number at the specefic index
            try{
                if (index < 0 || index >= m_size) {
                    throw 1;
                }
                m_size++;
                if(m_capacity == m_size){
                    m_arr = copy();
                }
                for(int i = m_size; i >= index; i--){
                    m_arr[i+1] = m_arr[i];
                }
                m_arr[index] = num;
            }catch(int err){
                if(err == 1){
                    std::cout << "Array index out of bound"<<"\n";
                }
            }
        }
        void del(int index){
            // deletes m_array memeber from chosen index
            try{
                if (index < 0 || index >= m_size) {
                    throw 1;
                } 
                for(int i = index; i < m_size; i++){
                    m_arr[i] = m_arr[i+1];
                }
            m_size--;  
            }catch(int err)
            {
                if(err == 1){
                    std::cout << "Array index out of bound"<<"\n";
                }
            }
            
        }
        void print(){
             for(int i = 0; i < m_size; i++){
                std::cout<<m_arr[i]<<" ";
            }
            std::cout<<std::endl;
        }

};
