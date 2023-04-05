#include <iostream>
#include "smart_array.hpp"
int* Array::change_capacity(){
//Creates new array with bigger capacity
//Copies values from old array to new array
//Deletes old array
//returns new array 
    m_capacity = m_size * 1.5;
    int* narr = new int[m_capacity]{0};
    for (int i = 0; i < m_size; i++){
        narr[i] = m_arr[i];  
    }
    delete [] m_arr;
    return narr;
}
Array::Array(){
//Default constructor
//Creates new array with capacity of 4
    m_capacity = 4;
    m_size = 0;
    m_arr = new int[m_capacity]{0};
}
Array::Array(int s){
//Creates array with specified size (s) and capacity of (1.5 * size)
    if(s <= 0){
        throw 2;
    }
    m_size = s;
    m_capacity = m_size * 1.5;
    m_arr = new int[m_capacity]{0};

}
Array::Array(int s, int a[]){
//Creates array with values of argument array
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
Array::~Array(){
//Deletes array
    delete [] m_arr;
}

int& Array::operator[](int index){
//operator for getting from index
   if (index < 0 || index >= m_size) {
       throw 1;
   }   
   return m_arr[index];
}

int Array::get_size(){
//returns user visible size
    return m_size;
}
void Array::push(int num){
//adds number at the end of Array
    m_size++;
    if(m_size == m_capacity){
        m_arr = change_capacity();
    }
    m_arr[m_size-1] = num;
}
void Array::insert(int num, int index){
//adds number at the specefic index
    if (index < 0 || index > m_size) {
        throw 1;
    }
    m_size++;
    if(m_capacity == m_size){
        m_arr = change_capacity();
    }
    for(int i = m_size-1; i >= index; i--){
    //moves all elements after index to the right 
    //creates duplicate of m_arr[index] on [index+1] position
        m_arr[i+1] = m_arr[i];
    }
    //overwrites m_arr[index]
    m_arr[index] = num;
}
void Array::del(int index){
// deletes array memeber from chosen index
    if (index < 0 || index >= m_size) {
        throw 1;
    } 
    for(int i = index; i < m_size; i++){
    //Moves all elements to the left starting from [index] position
    //overwrites m_arr[index]
        m_arr[i] = m_arr[i+1];
    }
    m_size--;  
}
void Array::print(){
//prints user visible elements of array
    for(int i = 0; i < m_size; i++){
        std::cout<<m_arr[i]<<" ";
    }
    std::cout<<std::endl;
}