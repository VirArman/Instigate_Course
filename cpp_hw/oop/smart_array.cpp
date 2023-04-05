#include <iostream>
#include "smart_array.hpp"
int* Arr::change_capacity(){
    m_capacity = m_size * 1.5;
    int* narr = new int[m_capacity]{0};
    for (int i = 0; i < m_size; i++){
        narr[i] = m_arr[i];  
    }
    delete [] m_arr;
    return narr;
}
Arr::Arr(){
    m_capacity = 4;
    m_size = 0;
    m_arr = new int[m_capacity]{0};
}
Arr::Arr(int s){
    if(s <= 0){
        throw 2;
    }
    m_size = s;
    m_capacity = m_size * 1.5;
    m_arr = new int[m_capacity]{0};

}
Arr::Arr(int s, int a[]){
    if(s <= 0){
        throw 2;
    }
    m_size = s;
    m_capacity = m_size * 1.5;
    m_arr = new int[m_capacity]{0};
    for(int i = 0; i < m_size; i++){
        m_arr[i] = a[i];
    }
}        
Arr::~Arr(){
    delete [] m_arr;
}

int& Arr::operator[](int index){
   if (index < 0 || index >= m_size) {
       throw 1;
   }   
   return m_arr[index];
}

int Arr::get_size()
{
    return m_size;
}
void Arr::push(int num){
    //adds number at the end of Array
    m_size++;
    if(m_size == m_capacity){
        m_arr = change_capacity();
    }
    m_arr[m_size-1] = num;
}
void Arr::insert(int num, int index){
    //adds number at the specefic index
    if (index < 0 || index > m_size) {
        throw 1;
    }
    m_size++;
    if(m_capacity == m_size){
        m_arr = change_capacity();
    }
    for(int i = m_size+1; i >= index; i--){
        m_arr[i] = m_arr[i-1];
    }
    m_arr[index] = num;

}
void Arr::del(int index){
    // deletes m_array memeber from chosen index
    if (index < 0 || index >= m_size) {
        throw 1;
    } 
    for(int i = index; i < m_size; i++){
        m_arr[i] = m_arr[i+1];
    }
    m_size--;  

}
void Arr::print(){
    for(int i = 0; i < m_size; i++){
        std::cout<<m_arr[i]<<" ";
    }
    std::cout<<std::endl;
}

