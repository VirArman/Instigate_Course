#include "Memory.hpp"
class ControlUnit{
    private:
        ALU alu;
        Memory ram;
    public:
        ControlUnit(){}
        ControlUnit(Memory& ram){
            this->ram = ram;
        }
        ControlUnit& operator=(const ControlUnit& other) {
            if (this != &other) {
                // Assign the ALU member
                alu = other.alu;
                // Assign the RAM member
                ram = other.ram;
            }
            return *this;
    }
        int fetch(int address){
            return ram.read(address);
        }
        
        int* decode(int code){
            int* res = new int[4];
            for(int i = 3; i >= 0; i-- ){
                res[i] = 0b1111 & code;
                code = code >> 4;
            }
            return res;
        }
        int execute(Registers& regs){
           return alu.execute(regs);
        }
        
};