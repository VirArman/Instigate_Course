#include "List.hpp"

class Queue{
    private:
    List queue;
    public:
    //adds element to end of queue
    void enqueue(int value);
    //removes element from the front of queue
    int dequeue();
    //check if the queue is full
    bool is_full();
    //check if the queue is empty
    bool is_empty();
    //get the value of the front of the queue without removing it
    int peek();
};