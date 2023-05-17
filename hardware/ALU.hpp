#include "Memory.hpp"
class ALU{
    public:
        int execute(Registers& regs, Memory* ram){
            int res;
            const int ADD = 0b0001;
            switch (regs.read(0)){
                case ADD:
                    res = ram->read(regs.read(2)) + ram->read(regs.read(3));
                    return res;
            
                default:
                    return -1;
                }
        }
};