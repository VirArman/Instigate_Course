#include <iostream>
#include "List.hpp"
int main(){
    List <int>l;
    l.push_front(1);
    l.push_back(5);
    l.push_back(78);
    l.insert(98,0);
    l.push_back(-13);
    l.push_back(4);
    l.print();
    //l.bubble_sort();
    l.insertion_sort();
    l.print();
    List l2 = l;
    l2.pop_back();
    std::cout<<l2.get_size()<<std::endl;
    l2.remove_by_index(1);
    l2.print();
    l2.remove_by_value(4);
    l2.reverse();
    l2.print();
    std::cout<<l2.get_size()<<std::endl;
}