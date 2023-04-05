#include <iostream>
#include "smart_array.hpp"
int main(){
    Arr a;
    for(int i = 1; i < 10; i++){
        a.push(i);
    }
    a.print();
    std::cout<< a.get_size() << "\n";
    a.insert(13,a.get_size());
    a.print(); 
    std::cout<< a.get_size() << "\n";
    return 0;
}
