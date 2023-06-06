#include "Memory.hpp"
class ALU{
    public:
        int execute(Registers& regs, Memory* ram){
            int res;
            const int ADD = 0b0001;
            const int SUB = 0b0010;
            const int DIV = 0b0011;
            const int MULT = 0b0101;
            switch (regs.read(0)){
                case ADD:
                    res = ram->read(regs.read(2)) + ram->read(regs.read(3));
                    return res;
                case SUB:
                    res = ram->read(regs.read(2)) - ram->read(regs.read(3));
                    return res;
                case DIV:
                    res = ram->read(regs.read(2)) / ram->read(regs.read(3));
                    return res;
                case MULT:
                    res = ram->read(regs.read(2)) * ram->read(regs.read(3));
                    return res; 
                default:
                    return -1;
                }
        }
};