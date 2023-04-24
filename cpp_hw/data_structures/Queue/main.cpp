#include <iostream>
#include "../headers/Queue.hpp"

int main(){
    Queue q;
    q.enqueue(12);
    q.enqueue(2);
    q.enqueue(56);
    q.enqueue(223);
    std::cout<<q.is_empty()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.is_empty()<<std::endl;
}