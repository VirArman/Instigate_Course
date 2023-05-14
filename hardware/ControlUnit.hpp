#include "Memory.hpp"
#include "ALU.hpp"
class ControlUnit{
    private:
        Memory ram = Memory(12);
        ALU alu;
    public:
        int fetch(int address){
            return ram.read(address);
        }
        void load(int instruction){
            ram.load(instruction);
        }
        void store(int data, int address){
            ram.rewrite(data,address);
        }
        int* decode(int code){
            int* res = new int[4];
            for(int i = 3; i >= 0; i-- ){
                res[i] = 0b1111 & code;
                code = code >> 4;
            }
            return res;
        }
        int execute(int r1, int r3, int r4){
            switch (r1){
                case 1:
                    return alu.ADD(ram.read(r3),ram.read(r4));
                default:
                    return -1;
                    break;
            }
        }
};