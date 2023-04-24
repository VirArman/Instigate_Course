#include "../headers/Queue.hpp"

void Queue::enqueue(int value){
    queue.push_front(value);
}

int Queue::dequeue(){
    return queue.pop_back();
}

bool Queue::is_empty(){
    return queue.is_empty();
}
bool Queue::is_full(){
    return !queue.is_empty();
}

int Queue::peek(){
    return queue.get_node(queue.get_size()-1) -> data;
}