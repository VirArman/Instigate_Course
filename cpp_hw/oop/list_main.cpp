#include <iostream>
#include "List.hpp"
int main(){
    List l;
    std::cout<<"is empty: "<<l.is_empty()<<"\n";
    l.push_back(14);
    l.push_back(56);
    l.insert(15,0);
    l.print();
    std::cout<<l.get_size()<<std::endl;
}