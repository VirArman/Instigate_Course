#include <iostream>
#include "List.hpp"
int main(){
    List <std::string>l;
    l.push_front("Hello");
    l.push_back("Hi");
    l.push_back("Konichwa");
    l.insert("Nihao",0);
    l.push_back("Gamarjoba");
    l.push_back("Aloha");
    List l2 = l;
    l2.pop_back();
    std::cout<<l2.get_size()<<std::endl;
    l2.remove_by_index(1);
    l2.print();
    l2.remove_by_value("Hi");
    l2.reverse();
    l2.print();
    std::cout<<l2.get_size()<<std::endl;
}