#include <iostream>
#include "smart_array.cpp"
int main(){
    Arr a;
    for(int i = 1; i < 10; i++){
        a.push(i);
    }
    a.print();
    std::cout<< a.len() << "\n";
    a.insert(13,a.len());
    a.print(); 
    std::cout<< a.len() << "\n";
    return 0;
}
