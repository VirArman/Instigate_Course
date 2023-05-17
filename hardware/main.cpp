#include <iostream>
#include <vector>
#include "Registers.hpp"
#include "ALU.hpp"
#include "ControlUnit.hpp"
#include "CPU.hpp"
Memory ram;
int main(){
    CPU cp(ram);
    cp.store(4,6);
    cp.store(5,7);
    cp.load(0b0001100001100111);
    cp.execute();
    ram.print();

    return 0;
}