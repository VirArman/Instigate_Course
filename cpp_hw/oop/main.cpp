#include <iostream>
#include "smart_array.cpp"
int main(){
    Arr a;
    int ba[] = {1,3,46};
    Arr b(3,ba);
    b.print();
    for(int i = 1; i < 10; i++){
        a.push(i);
    }
    a.print();
    std::cout<< a.len() << "\n"; 
    a.insert(13,-3);
    a.insert(13,8);
    a.del(-6);
    a.del(6);
    std::cout<< a.len() << "\n"; 
    a.print();
    Arr c(-5);
    return 0;
}
