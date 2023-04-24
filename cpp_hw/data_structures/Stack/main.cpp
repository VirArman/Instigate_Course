#include <iostream>
#include "../headers/stack.hpp"

int main(){
    Stack st;
    st.push(12);
    st.push(132);
    st.push(2456);
    st.push(65);
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
}