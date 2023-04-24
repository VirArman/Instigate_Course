#include "../headers/stack.hpp"

int main(){
    Stack st;
    st.push(12);
    st.push(132);
    st.push(2456);
    st.push(65);
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
}