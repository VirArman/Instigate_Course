#include <iostream>
#include "List.hpp"
int main(){
    try
    {
        List l;
        l.push_back(14);
        l.push_back(56);
        l.push_back(25);
        l.push_back(95);
        List l2 = l;
        //l[1] = 4;
        l.print();
        //l.pop_back();
        //l.remove_by_index(0);
        //l.remove_by_value(14);//needs fix
        l.print();
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