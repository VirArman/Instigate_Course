#include <iostream>
#include <vector>
#include "Registers.hpp"
#include "ALU.hpp"
#include "ControlUnit.hpp"
#include "CPU.hpp"
Memory ram;
int main(){
    CPU cp(ram);
    int instructions[] = {
        0b0001100001100111,
        0b0010100101110110,
        0b0011101001110110,
        0b0101101101100111,
    };
    cp.store(4,6);
    cp.store(5,7);
    for(int i = 0; i < 4; i++){
        cp.load(instructions[i]);
        cp.execute();
    }
    ram.print();

    return 0;
}