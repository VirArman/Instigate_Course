class Registers{
    private:
        int registers[6] = {0};
        //registers[0]->stores operation
        //registers[1]->stores address of result
        //registers[2]->stores address of first operand
        //registers[3]->stores address of second operand
        //registers[4]->stores address of the next instruction
        //registers[5]->stores address of instruction to be loaded
    public:
        
        void write(int data, int index){
            registers[index] = data;
        }
        int read(int index){
            return index;
        }
};