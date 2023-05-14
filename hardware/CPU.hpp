#include "ControlUnit.hpp"

class CPU{
    private:
        int r1;// stores operation to use
        int r2;// stores address where to store result of instructions
        int r3;// stores address of first operand 
        int r4;// stores address of second operand
        int PC = 0;// stores address of the next instruction
        ControlUnit CU;
    public:
        void load(int instruction){
            CU.load(instruction);
        }
        void execute(){
            int instruction = CU.fetch(PC);
            int* decoded = CU.decode(instruction);
            r1 = decoded[0];
            r2 = decoded[1];
            r3 = decoded[2];
            r4 = decoded[3];
            CU.store(CU.execute(r1,r3,r4),r2);
            PC++;
        }
        void print(){
            CU.print();
        }
};