#include <iostream>
#include "../headers/List.hpp"
int main(){
    try
    {
        List l;
        l.push_front(-98);
        l.push_back(14);
        l.push_back(56);
        l.insert(456,0);
        l.push_back(25);
        l.push_back(95);
        l.print();
        List l2 = l;
        l2.print();
        l[1] = 4;
        l.print();
        l2.pop_back();
        l2.remove_by_index(0);
        l2.remove_by_value(56);
        l2.print();
        std::cout<<l2.get_size()<<std::endl;
    }
    catch(int e)
    {
        if(e == 1){
            std::cout<<1<<"\n";
        }
        if(e == 2){
            std::cout<<2<<"\n";
        }
        if(e == 3){
            std::cout<<3<<"\n";
        }
    }
    

}